#include <iostream>

using namespace std;

/*
Search in a row wise and column wise sorted matrix
*/

int search(int mat[][4], int rows, int num) {
    // start search from top right position
    int i = 0;
    int j = rows-1;
    
    while ( (i < rows) && (j >= 0) ){
        cout << mat[i][j] << endl;
        if(num == mat[i][j]) {
            cout << "Element found at ["<<i<<","<<j<<"]"<<endl;
            return 1;
        }
        if(num < mat[i][j]) {
            //move left
            j--;
        } else {
            //move right
            i++;
        }
    }
    cout << "Element not found" << endl;
    return 0;
}

int main() {
    int rows = 4;
    int cols = 4;
    
    int num = 46;
    
    int mat[][4] = {{10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 46, 50},
    };
    
    search(mat, rows, num);
    return 0;
}
