#include <iostream>

using namespace std;
/*
Backtracking algo:
Sudoku

Psuedocode:
1. Find unassigned Row,Col from the Grid.
2. If there is none, return true
3. From number 1 to 9, start loop
    a) allocate number to Row, Col
    b) check if number is valid for Row,Col
        i) if true, then recursively fill in rest of grid by calling step#1
        ii) if recursion succeeds then return true
        ii) else, backtrack by unassigning to Row,Col and go to next of step#3
4. return false - No number can be allocated for Row,Col
    
*/

#define N 9

// return unassigned block from the grid
bool unassignedLoc(int grid[][N], int& row, int& col) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

// check for conflicts
bool isvalid(int grid[][N], int num, int row, int col) {
    //check row for conflicts
    for(int i=0; i<N; i++) {
        if(grid[row][i] == num)
            return false;
    }
    //check column for conflicts
    for(int i=0; i<N; i++) {
        if(grid[i][col] == num)
            return false;
    }
    //check 3*3 sub-grid for conflicts
    int rowstartgrid = row - row%3;
    int colstartgrid = col - col%3;
    for(int i=rowstartgrid, j=colstartgrid; i<3&&j<3; i++,j++) {
        if(grid[i][j] == num) {
            return false;
        }
    }
    return true;
}

bool SolveSudoku(int grid[][N]) {
    int row, col;
    if(!unassignedLoc(grid, row, col)) {
        return true; // All full
    }
    //You have got one row,col
    for(int num=1; num<=9; num++) {
	bool success = false;
        if(isvalid(grid,num,row,col)) {
            grid[row][col] = num;
            success = SolveSudoku(grid); //find unasigned locations
        }
        if(success)
            return true;
        grid[row][col] = 0;
    }
    return false; // No number can be allocated for this Row and Col
}

void printGrid(int grid[][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSudoku(grid) == true) {
        cout << "Solution exists" << endl;  
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}

