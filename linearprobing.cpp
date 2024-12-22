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
// linear probing
void insertion(int rn, string name,int attempt=0)
{
    float lf=count/tsize;
    if(lf>=0.7){
        rehash();
    }
    int hv =( (rn+attempt) % tsize);    // Computing the hash value
    if (table[hv].isempty){   // Insert in the table if there is no collision
        table[hv].rn=rn;
        table[hv].name=name;
        table[hv].isempty=false;
        cout<<"Inserted "<<name<<","<<rn<<endl;
        count++;
    }
    else {
       insertion(rn,name,attempt+1);
    }
}
void rehash() {
    int newSize = tsize * 2;  
    SR* ntable = new SR[newSize];  
    int oldSize = tsize;
    SR* oldTable = table;  
    tsize = newSize;  
    table = ntable; 
    count = 0;  
    for (int i = 0; i < oldSize; i++) {
        if (!oldTable[i].isempty) {
            insertion(oldTable[i].rn, oldTable[i].name, 0);
        }
    }

    delete[] oldTable;  
    cout << "Rehashed to size " << tsize << endl;
}

void searching(int rn,int attempt=0){
    int hv = ( (rn+attempt) % tsize);    // Computing the hash value
    if (!table[hv].isempty && table[hv].rn==rn){   
        cout<<"Record found: "<<table[hv].name<<endl;
        return;
    }
    if (table[hv].isempty){   
        cout<<"Record not found"<<endl;
        return;
    }
    else {
       searching(rn,attempt+1);
    }
}
void deletion(int rn,int attempt=0){
    int hv= ( (rn+attempt) % tsize);    // Computing the hash value
    if (table[hv].isempty){   
        cout<<"Record not found"<<endl;
        return;
    }
    if (table[hv].rn==rn){   
        table[hv].rn=-1;
        table[hv].name=" ";
        cout<<"Record Deleted "<<endl;
        count--;
        return;
    }
    else {
        deletion(rn,attempt+1);
    }
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
    record r(5);//an instance of the record class
    // Inserting records into the hash table
    r.insertion( 31, "falah");
    r.insertion(18, "manya");
    r.insertion( 23, "maru");
    r.insertion( 34, "mala");
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