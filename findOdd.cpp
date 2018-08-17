#include <iostream>

using namespace std;

unsigned int findOdd(unsigned int arr[], int size){
    unsigned int result = 0;
    for (int i = 0; i != size; ++i){
        result ^= arr[i];
    }
    return result;
}

int main(){
    unsigned int arr[] = {5, 10, 15, 20, 25, 20, 15, 10, 5};
    int arrSize = sizeof(arr) / sizeof(int);
    
    cout << "Odd element is " << findOdd(arr, arrSize) << endl;

    return 0;
}