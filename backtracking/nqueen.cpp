#include <iostream>

using namespace std;
/*
Backtracking algorithm:
N Queen problem
*/
#define N 4
bool util(int x, int board[][N]);

void printsol(int board[][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cout << board[i][j] << " ";
    cout << endl;
    }
}
bool validcol(int x, int y, int board[][N]) {
    for(int i=0; i<N; i++) {
        if(board[x][i] == 1) // already one queen is placed in this row
            return false;
        if(board[i][y] == 1) // already one queen is placed in this column
            return false;
    }
    // check for left diagonal upwards
    for(int i=x,j=y; i>=0 && j>=0; i--,j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    //check for right diagonal upwards
    for(int i=x,j=y; i<N && j<N; i--,j++) {
        if(board[i][j] == 1)
            return false;
    }
    return true;
}

void solveNqueen(){
    int board[N][N] = {0};
    board[0][0] = 1;
    bool result = util(0, board);
    if(result) {
        cout << "Solved" << endl;
        printsol(board);
    } else {
        cout << "Not solved" << endl;
    }        
}

bool util(int x, int board[][N]) {
    // passed end row
    if(x==N)
        return true;
        
    // run for all columns in a row
    for(int j=0; j<N; j++) {
        bool success = false;
        //if valid column go for next row else run for next column
        if(validcol(x, j, board)) {
            board[x][j] = 1;
            success = util(x+1, board);
        } 
        // if current move is not success then backtrack
        if(!success) {
            board[x][j] = 0;
        } else {
            return true;
        }
        
    }
    //not success for all columns in a row
    return false;
}


int main()
{
 
    solveNqueen();
    return 0;
}

