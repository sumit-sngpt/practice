#include <iostream>

using namespace std;

/*
Backtracking algorithm:
Print all permutations of a given string
*/

static int permutations = 0;
void swap(char* first, char* second) {
    //cout << *first << "=>" << *second << endl;
    char temp = *first;
    *first = *second;
    *second = temp;
}


void permute(char* str, int start, int end) {
    //cout << start << ":" << end << endl;
    int j;
    if(start==end){
        permutations++;
        cout << str << endl;
    } else {
        for(j=start; j<=end; j++) {
            swap((str+start),(str+j));
            permute(str, start+1, end);
            swap((str+start),(str+j));
        }
        
    }
}

int main()
{
    char str[] = "sumit";
    int size = sizeof(str)/sizeof(str[0]);
    permute(str, 0, size-2);
    cout << "Total permutations: " << permutations << endl; 
    return 0;
}

