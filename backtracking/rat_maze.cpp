#include <iostream>

using namespace std;
/*
Backtracking algorithm:
Rat in a Maze ( Rat can move only forward and down)
*/

#define N 4

//check if the current move is valid move or not
bool validmove(int x, int y, int maze[][N]) {
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
        return true;
    return false;
}

bool util(int, int, int[N][N], int[N][N], int);

// Print the solution matrix
void printsol(int soln[][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cout << soln[i][j] << " ";
        cout << endl;
    }
}

void solve(int maze[][N]) {
    
    //solution matrix will contain move numbers, else -1
    int soln[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            soln[i][j] = -1;
        }
    }
    
    // start from source
    bool result  = util(0, 0, maze, soln, 1);
    
    if(result) {
        cout << "Problem solved" << endl;
        printsol(soln);
    } else {
        cout << "Problem can't be solved" << endl;
    }
     
}


bool util(int x, int y, int maze[][N], int soln[N][N], int movenum) {
    
    //Rat reached destination
    if (x==N-1 && y==N-1) {
        soln[x][y] = movenum;
        return true;
    }

    //check if present move is valid or not
    //if current move is valid then go for next move else return
    if(validmove(x, y, maze)) {
        soln[x][y] = movenum;
        //move only forward or down direction
        // move down
        bool movesuccess = util(x+1, y, maze, soln, movenum+1);
        // if can't move down then move forward
        if(!movesuccess)
            movesuccess = util(x, y+1, maze, soln, movenum+1);
        
        if(!movesuccess)
            soln[x][y] = -1;
        else
            return true;
    }
    return false;
}

int main()
{
    int maze[N][N] = {{1, 1, 0, 0},
                {0, 1, 1, 1},
                {0, 0, 0, 1},
                {0, 1, 1, 1}};
    solve(maze);
    return 0;
}

