#include <iostream>
using namespace std;

struct SR{
    string name;
    int rn;
    bool isempty;
    SR() : isempty(false) {}
};

// Function to print an array
void printArray(SR arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i].name <<endl;
        cout << arr[i].rn <<endl;
    }
}
// quadratic probing
void hashing(SR table[], int rn, string name)
{
    int hv = rn % 8;    // Computing the hash value
    if (table[hv].isempty){   // Insert in the table if there is no collision
        table[hv].rn=rn;
        table[hv].name=name;
        table[hv].isempty=false;
    }
    else {
        for (int j = 1; j <= 8; j++) {   // If there is a collision iterating through all possible quadratic values
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
}
void searching(int rn,int tsize,SR table[]){
    int hv = rn % 8;    // Computing the hash value
    if (table[hv].rn==rn){   
        cout<<"Record found: "<<table[hv].name<<endl;
        return;
    }
    else {
        for (int j = 1; j <= 8; j++) {   
            int t = (hv + j * j) % 8;    
            if (!table[t].isempty && table[t].rn==rn) {
                cout<<"Record found: "<<table[t].name<<endl;
                return;
            }
        }
    }
    cout<<"Record not found"<<endl;
}
int main()
{
    // Size of the hash table
    int tsize = 8;
    SR hash_table[8];
    // Initializing the hash table
    for (int i = 0; i < tsize; i++) {
        hash_table[i].isempty = true;
    }
    hashing(hash_table, 31,"falah");
    hashing(hash_table, 18,"manya");
    hashing(hash_table, 23,"maru");
    hashing(hash_table, 34,"mala");
    hashing(hash_table, 16,"peter");
    searching(31,tsize,hash_table);
    searching(16,tsize,hash_table);
    searching(10,tsize,hash_table);
    return 0;
}