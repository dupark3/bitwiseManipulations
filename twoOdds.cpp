#include <iostream>
#include <vector>

using namespace std;

vector<int> findTwoOdds(const vector<int>& nums){
    // every number repeats an even number of times except two numbers, which
    // repeat an odd number of times -- O(n) time and O(1) space complexities
    
    // first, get the xor of every number
    int xorTotal = 0;
    for (int num : nums){
        xorTotal ^= num;
    }
    cout << xorTotal << endl;
    
    // find the right most bit that is set
    int set_bit = xorTotal & ~(xorTotal - 1);
    
    // sort them by the right most set bit
    int xor1 = 0, xor2 = 0;
    for (int num : nums){
        if (num & set_bit){
            xor1 ^= num;
        } else {
            xor2 ^= num;
        }
    }

    return {xor1, xor2}; 
}

int main(){
    vector<int> nums = {1, 2, 3, 13, 100, 3, 2, 1};
    
    for (int num : findTwoOdds(nums)){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}