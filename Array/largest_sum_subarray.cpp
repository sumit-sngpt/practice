#include <iostream>

using namespace std;

/*
Largest Sum Contiguous Subarray
*/
int find_largest_sum(int arr[], int size) {
    int max_sum = arr[0];
    int curr_sum = arr[0];
    for (int i=1; i< size; i++){
        curr_sum = (arr[i] > curr_sum+arr[i]) ? arr[i] : curr_sum+arr[i]; // check if continuous sum of current and next element is larger than next element
        max_sum = (curr_sum > max_sum) ? curr_sum : max_sum;
    }
    return max_sum;
}

int main(){
    
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int sum = find_largest_sum(arr, arr_size);
    cout << "Largest sum from contiguous subarray is "<< sum << endl;
    return 0;
}


