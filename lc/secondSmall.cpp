//
//  main.cpp
//  secondSmall
//
//

#include <iostream>
#include <vector>
using namespace std;
int secondSmall(vector<int>nums){
    int second = INT_MAX;
    int min = INT_MAX;
    for(int num : nums){
        if(num < second){
            second = num;
            if(num < min){
                second = min;
                min = num;
            }
        }
    }
    return second;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>nums{3,6,2,6,1,-1};
    cout<<secondSmall(nums)<<endl;
    return 0;
}
