/*Implement a C++ class to manage student records in a hash table with a size
of 15. Use quadratic probing for collision resolution with the formula (index + attempt^2) % table
size.Implement a insert function which takes a student's roll number and name, inserting
the record into the hash table using quadratic probing.Implement a search function which
takes a roll number, searches for the corresponding record using quadratic probing, and prints
the student's name if found; otherwise, print a "Record not found" message.*/

#include <iostream>
using namespace std;
struct SR{
string name;
int rn;
bool isempty;
SR() : isempty(true), rn(-1), name("") {} 
};
class record{
public:
SR* table;  // Pointer to the hash table array
int tsize;  // Size of the hash table
int count=0;
// Constructor 
record(int size) : tsize(size) {
    table = new SR[tsize]; 
    for (int i = 0; i < tsize; i++) {
        table[i].isempty = true;  // Set all entries as empty initially
    }
}

void insertion(int rn, string name)
{
    float lf=count/tsize;
    if(lf>=0.7){
        rehash();
    }
    int hv = rn % tsize;    // Computing the hash value
    if (table[hv].isempty){   // Insert in the table if there is no collision
        table[hv].rn=rn;
        table[hv].name=name;
        table[hv].isempty=false;
    }
    else {
        for (int j = 1; j <= tsize; j++) {   // If there is a collision iterating through all possible quadratic values
                int t = (hv + j * j) % 8;    // Computing the new hash value
                if (table[t].isempty) {
                    table[t].rn=rn;
                    table[t].name=name;
                    table[t].isempty=false;
                    break;
                }
            }
    }
    cout<<"Inserted "<<name<<","<<rn<<endl;
    count++;
}
void rehash() {
    int newSize = tsize * 2; 
    SR* newTable = new SR[newSize]; 
    for (int i = 0; i < newSize; i++) { 
        newTable[i].isempty = true;
    }
    for (int i = 0; i < tsize; i++) {
        if (!table[i].isempty) { // Reinsert only non-empty elements
            int newHv = table[i].rn % newSize; // recalculate hash value 
            if (newTable[newHv].isempty) {       // no collision
                newTable[newHv] = table[i];
            } else {                        //  quadratic probing
                for (int j = 1; j <= newSize; j++) {
                    int t = (newHv + j*j) % newSize;
                    if (newTable[t].isempty) {
                        newTable[t] =table[i];
                        break;
                    }
                }
            }
        }
    }
    delete[] table; 
    table = newTable; 
    tsize = newSize; 
    cout << "Rehashed to size " << tsize << endl;
}
void searching(int rn){
    int hv = rn % tsize;    // Computing the hash value
    if (table[hv].rn==rn){   
        cout<<"Record found: "<<table[hv].name<<endl;
        return;
    }
    else {
        for (int j = 1; j <= tsize; j++) {   
            int t = (hv + j * j) % 8;    
            if (!table[t].isempty && table[t].rn==rn) {
                cout<<"Record found: "<<table[t].name<<endl;
                return;
            }
        }
    }
    cout<<"Record not found"<<endl;
}
void deletion(int rn){
    int hv = rn % tsize;    // Computing the hash value
    if (table[hv].rn==rn){   
        table[hv].isempty=true;
        table[hv].rn=-1;
        table[hv].name=" ";
        cout<<"Record Deleted "<<endl;
        return;
    }
    else {
        for (int j = 1; j <= 8; j++) {   
            int t = (hv + j * j) % tsize;    
            if (!table[t].isempty && table[t].rn==rn) {
                table[hv].isempty=true;
                table[hv].rn=-1;
                table[hv].name=" ";
                cout<<"Record Deleted "<<endl;
                return;
            }
        }
    }
    cout<<"Record not found"<<endl;
}
void printtable(){
    cout<<"Hash Table"<<endl;
    for(int i=0;i<tsize;i++){
        cout<<table[i].name<<"-"<<table[i].rn<<endl;
    }
    return;
}
};
int main()
{
    record r(15);//an instance of the record class
    // Inserting records into the hash table
    r.insertion( 31, "falah");
    r.insertion(18, "ahsn");
    r.insertion( 23, "mars");
    r.insertion( 34, "jumi");
    r.insertion( 16, "peter");
    r.insertion( 22, "jj");
    r.insertion( 90, "lala");
    // Searching for records
    r.searching(31);
    r.searching(16);
    r.searching(10);
    r.printtable();
    // Deleting a record and searching again
    r.deletion(18);
    r.searching(18);
    r.printtable();
    return 0;
}
