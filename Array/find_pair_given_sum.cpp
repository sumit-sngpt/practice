#include <iostream>

using namespace std;
#define MAX 50

/*
Given an array A[] and a number x, check for pair in A[] with sum as x
*/

void search_pair(int arr[], int arr_size, int sum) {
    if (sum > MAX) {
        cout << "Sum shouldn't be greater than " << MAX << endl;
        return;
    } 
    int temp_map[MAX] = {0};
    
    for(int i=0; i < arr_size; i++) {
        
        if(sum <= arr[i])
            continue;
        
        int diff = sum - arr[i];
        
        if(temp_map[diff] == 1) {
            cout << arr[i] << " and " << diff << endl;
            return;
        } else {
            temp_map[arr[i]] = 1;
        }
    }
    cout << "No matching pairs found" << endl;
}


int main(){
    
    int arr[] = {1, 4, 45, 6, 3, 8};
    int sum = 48;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    search_pair(arr, arr_size, sum);
    return 0;
}


