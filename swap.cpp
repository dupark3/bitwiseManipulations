#include <iostream>

using namespace std;

void swap(unsigned int& x, unsigned int& y){
    if (x == y){
        return;
    }

    x ^= y; // x = x and y, y = y
    y ^= x; // x = x and y, y = x
    x ^= y; // x = y and y = x
}

int main(){
    unsigned int x = 10, y = 10;
    cout << "x is " << x << " and y is " << y << endl;
    swap(x, y);
    cout << "x is " << x << " and y is " << y << endl;

    return 0;
}