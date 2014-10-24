#include <iostream>

using namespace std;

// Maximum size square sub-matrix with all 1s
void print_max_square_sub_matrix(int mat[][5], int rows, int cols) {
    int processed[rows][cols];
    int max_value = 0;
    int max_i = 0;
    int max_j = 0;
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if(i==0 || j==0 ) {
                processed[i][j] = mat[i][j];
            } else {
                if(mat[i][j] == 0) {
                    processed[i][j] = 0;
                } else {
                    int min = (processed[i-1][j] < processed[i][j-1]) ? processed[i-1][j] : processed[i][j-1];
                    min = (min < processed[i-1][j-1]) ? min : processed[i-1][j-1];
                    processed[i][j] = min + 1;
                    if(max_value < processed[i][j]) {
                        max_value = processed[i][j];
                        max_i = i;
                        max_j = j;
                    }
                } 
            }
        }
    }
    cout << "Max square sub-matrix size: " << max_value << " * " << max_value << endl;
    cout << "Matrix ends at co-ordinates : " << max_i << " and " << max_j << endl;
    cout << "Matrix is: " << endl;
    for(int i=max_i; i>(max_i - max_value); i--){
        for(int j=max_j; j>(max_j - max_value); j--) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int rows = 6;
    int cols = 5;
    int mat[][5] = {{0,1,1,0,1},
        {1,1,1,1,0},
        {1,1,1,1,0},
        {1,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0}};
        
    print_max_square_sub_matrix(mat, rows, cols);
    
   return 0;
}
