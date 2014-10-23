#include <iostream>

using namespace std;

// Print row number that contains max number of Ones
int find_max_one_row(int mat[][6], int rows, int cols) {
    int last_index = cols;
    int row_number = 0;
    int number_of_iterations = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < last_index; j++){
            number_of_iterations++;
            if(mat[i][j] == 0){
                continue;
            } else {
                row_number = i;
                last_index = j;
                break;
            }
        }
    }
    cout << "Total iterations: " << number_of_iterations << endl;
    return row_number;
}

int main()
{
    int rows = 5;
    int cols = 6;
    int mat[][6] = {{0,0,0,0,0,0},
        {0,0,1,1,1,1},
        {0,0,0,0,1,1},
        {1,1,1,1,1,1},
        {0,1,1,1,1,1}};
    int max_one_row = find_max_one_row(mat, rows, cols);
    cout << "The row number is: " << max_one_row << " which contains max number of Ones" << endl;
   return 0;
}

