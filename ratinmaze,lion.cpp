#include <iostream>
using namespace std;
bool isSafe(int arr[][5], int x, int y) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5 && arr[x][y] == 1) {
        return true;
    }
    return false;
}
bool lion(int arr[][5], int x, int y, int solArr[][5]) {
    if (x == 4 && y == 4) {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y)) {
        solArr[x][y] = 1;

        if (lion(arr, x, y+1, solArr)) {
            return true;
        }

        if (lion(arr, x+1, y, solArr)) {
            return true;
        }
        if (lion(arr, x, y-1, solArr)) {
            return true;
        }

        if (lion(arr, x-1, y, solArr)) {
            return true;
        }

        solArr[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    int maze[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };
    int solArr[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    cout<<"Maze:"<<endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    } 
    if (lion(maze, 0, 0, solArr)) {
        cout << "Solution Path:" << endl;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}


