#include <iostream>

using namespace std;

/*
Print a given matrix in spiral form
*/

void print_spiral(int mat[][6], int rows, int cols) {
    int col_limit = cols;
    int row_limit = rows;
    
    int first_row = 0;
    int first_col = 0;
    int last_row = row_limit - 1;
    int last_col = col_limit - 1;
    
    int i,j;
    
    while ( (first_row < last_row) && (first_col < last_col) ) {

        cout << "Pointers are now at: ";
        cout << first_row << "," << last_row << "," << first_col << "," << last_col << "," << endl;
    
        // print first row
        i = first_row;
        for(j=first_col; j<=last_col; j++){
            cout << mat[i][j] << ",";
        }
        cout << endl;
        first_row++;
        cout << "Pointers are now at: ";
        cout << first_row << "," << last_row << "," << first_col << "," << last_col << "," << endl;
    
        // print last column
        j = last_col;
        for(i=first_row; i<=last_row; i++){
            cout << mat[i][j] << ',';
        }
        cout << endl;
        last_col--;
        cout << "Pointers are now at: ";
        cout << first_row << "," << last_row << "," << first_col << "," << last_col << "," << endl;
    
        // print last row
        i = last_row;
        for(j=last_col; j>=first_col; j--){
            cout << mat[i][j] << ',';
        }
        cout << endl;
        last_row--;
        cout << "Pointers are now at: ";
        cout << first_row << "," << last_row << "," << first_col << "," << last_col << "," << endl;
    
        // print first column
        j = first_col;
        for(i=last_row; i>=first_row; i--){
            cout << mat[i][j] << ',';
        }
        cout << endl;
        first_col++;
        
        cout << "Pointers are now at: ";
        cout << first_row << "," << last_row << "," << first_col << "," << last_col << "," << endl;
    }
}

int main() {
    int rows = 3;
    int cols = 6;
    /*
    int mat[][4] = {{1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}};
    */
    int mat[][6] = {{1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18}};
    print_spiral(mat, rows, cols);
        
}
