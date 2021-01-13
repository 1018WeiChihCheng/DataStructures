//
//  main.cpp
//  slidingWAvg
//
//

#include <iostream>
#include <vector>
using namespace std;
double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    if(n < k){
        return 0.0;
    }
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += nums[i];
    }
    int result = sum;
    for(int i = k; i < n; i++){
        sum -= nums[i - k];
        sum += nums[i];
        result = max(result, sum);
    }
    return (double)result / k;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>nums = {1,12,-5,-6,50,3,4};
    cout<<findMaxAverage(nums,4)<<endl;
    return 0;
}
