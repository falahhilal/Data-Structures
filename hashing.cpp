#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// quadratic probing
void hashing(int table[], int tsize, int arr[], int n)
{
    // Iterating through the array
    for (int i = 0; i < n; i++) {
        int hv = arr[i] % tsize;    // Computing the hash value
        if (table[hv] == -1)     
            table[hv] = arr[i];      // Insert in the table if there is no collision
        else {
            for (int j = 1; j <= tsize; j++) {  // If there is a collision iterating through all possible quadratic values
                int t = (hv + j * j) % tsize;    // Computing the new hash value
                if (table[t] == -1) {
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
    printArray(table, tsize);
}
int main()
{
    int arr[] = { 50, 700, 76, 85, 92, 73, 101 };
    int n = sizeof(arr)/sizeof(arr[0]);

    // Size of the hash table
    int tsize = 11;
    int hash_table[11];

    // Initializing the hash table
    for (int i = 0; i < tsize; i++) {
        hash_table[i] = -1;
    }

    hashing(hash_table, tsize, arr, n);
    return 0;
}