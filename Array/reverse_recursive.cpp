#include <iostream>

using namespace std;

/*
Reverse an array in recursive way
*/

void reverse(int arr[], int first, int last) {
    cout << first << last << endl;
    if(first > last) {
        return;
    }
    int temp = arr[first];
    arr[first] = arr[last];
    arr[last] = temp;
    reverse(arr, first+1, last-1);
}



int main(){
    
    int arr[] = {1, 4, 45, 6, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, 0, arr_size-1);
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
    return 0;
}


