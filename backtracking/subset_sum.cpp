#include <iostream>

using namespace std;
/*
Backtracking algo:
Subset Sum problem - considering all numbers are non-negative and input set is unique.

Psuedocode:
1. start a loop for all elements in a set
2. for each element in set
3. remaining_sum -= number, update the result vector corresponding to this number
4. if remaining_sum == 0, return true
5. if remaining_sum > 0,
    a) recursively start from step#1, with new set that excludes the current element and previous elements
    b) if above recursion successful, return true
    c) if fails, backtrack by reupdate the result vector corresponding to this number
6. go to next element in the loop from step#1
7. outside the loop, return false
*/

#define N 20

void printset(int set[N], int vector[N], int size) {
    for(int i=0; i<size; i++) {
        if(vector[i]) {
            cout << set[i] << " ";
        }
    }
    cout << endl;
}

bool solveSubset(int set[N], int vector[N], int remain_sum, int nexti, int size) {
    if(nexti >= size) 
	return false;

    for(int i=nexti; i<size; i++) {
        
        int number = set[i];
        remain_sum -= number;
        
        vector[i] = 1;
        if(remain_sum == 0) {
            return true;
        } else if(remain_sum > 0) {
            bool success = solveSubset(set, vector, remain_sum, i+1, size);
            if(success) {
                return true;
            } 
        }
        vector[i] = 0; //backtrack
	remain_sum += number;
    }
    return false;
}

void generateSubsets(int set[N], int size, int Sum) {
    int vector[N] = {0};
    bool success = solveSubset(set, vector, Sum, 0, size);
    if(success) {
        cout << "Solution exists" << endl;
        printset(set, vector, size);
    } else {
        cout << "Solution doesn't exist" << endl;
    }
}


int main()
{
    int weights[] = {10, 7, 5, 19, 12, 20, 15};
    int size = sizeof(weights)/sizeof(weights[0]);
    if(size>N) {
        cout << "Input array should be less than " << N << endl;
        return 1;
    }
    generateSubsets(weights, size, 49);
    return 0;
}

