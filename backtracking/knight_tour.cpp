#include <iostream>

using namespace std;

/*
Backtracking algorithm:
The Knight’s tour problem
*/
#define N 8

bool isvalid(int soln[][N], int x, int y) {
    //cout << x << ":" << y << ":" << soln[x][y] << endl;
    if(x>=0 && x<N && y>=0 && y<N && soln[x][y] == -1)
        return true;
    else
        return false;
}

bool util(int, int, int, int[][N], int[], int[]);

void printsol(int soln[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cout << soln[i][j] << " ";
        }
        cout << endl;
    }
}

void solveKT() {
    int soln[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            soln[i][j]= -1;
        }
    }
    soln[0][0] = 0;
    
    int xmove[] = {-2, -2, 2, 2, -1, 1, -1, 1};
    int ymove[] = {-1, 1, -1, 1, -2, -2, 2, 2};
    
    int movenum = 1;
    bool issuccess = util(0, 0, movenum, soln, xmove, ymove); // util(x,y,movei,soln[][],xmove[],ymove[])
    if(issuccess) {
        cout << "The board is solved" << endl;
        printsol(soln);
    } else {
        cout << "Cannot be resolved" << endl;
    }
}

bool util(int x, int y, int movenum, int soln[][N], int xmove[N], int ymove[N]) {
    cout << x << ":" << y << ":" << movenum << endl;
    if (movenum == N*N) 
        return true;
    for(int k = 0; k < N; k++) {
        int xnext = x + xmove[k];
        int ynext = y + ymove[k];
        //cout << xnext << ":" << ynext << endl;
        if (isvalid(soln, xnext, ynext)) {
            soln[xnext][ynext] = movenum;
            bool result = util(xnext, ynext, movenum+1, soln, xmove, ymove);
            if(result == true) {
                return true;
            } else {
                soln[xnext][ynext] = -1; //backtrack
            }
        } 
    }
    return false;
}



int main()
{
    solveKT();
    return 0;
}

