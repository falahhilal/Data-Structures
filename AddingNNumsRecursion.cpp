#include <iostream>
using namespace std;

// Function to recursively add numbers from 1 to n
int sum(int n) {
    if (n <= 1)
        return n;
    return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of numbers from 1 to " << n << " is: " << sum(n) << endl;

    return 0;
}

