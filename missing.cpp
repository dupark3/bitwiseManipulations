#include <iostream>

using namespace std;

unsigned int findMissing(unsigned int arr[], int size){
    unsigned int result = 0;
    // flip result for all elements in array
    // flip result again for ints 1 to size - 1
    for (int i = 0; i != size; ++i){
        result ^= arr[i];
        result ^= i + 1;
    }

    // include size + 1 to capture the last integer
    result ^= size + 1;

    return result;
}

int main(){
    unsigned int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12};
    int arrSize = sizeof(arr) / sizeof(int);
    cout << "size : " << arrSize << endl;

    cout << "Missing element is " << findMissing(arr, arrSize) << endl;

    return 0;
}