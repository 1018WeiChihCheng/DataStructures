//
//  main.cpp
//  strangeSort
//  Negative number cases considered.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool ComparePair(pair<string,int>p1,pair<string,int>p2){
    return p1.second < p2.second;
}
vector<string> strangeSort(vector<string>&nums,vector<int>&mapping){
    unordered_map<int,int>idxMap;
    int i = 0;
    //store the mapping between strange and correct.
    //(3,0) (5,1) (4,2)...
    for(int num : mapping){
        idxMap[num] = i++;
    }
    vector<pair<string,int>>buffer;
    for(i = 0; i < nums.size(); i++){
        string curr = nums[i];
        string modifiedCurr = "";
        bool isNegative = false;
        for(int j = 0; j < curr.size(); j++){
            if(j == 0 && curr[j] == '-'){
                isNegative = true;
                continue;
            }
            modifiedCurr += to_string(idxMap[(curr[j] - '0')]);
        }
        int num_ = (isNegative)? -1 * stoi(modifiedCurr) : stoi(modifiedCurr);
        buffer.push_back(pair<string,int>(curr,num_));
    }
    stable_sort(buffer.begin(), buffer.end(), ComparePair);
    
    vector<string>result;
    for(pair<string,int> p : buffer){
        result.push_back(p.first);
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string>nums{"990","332","32"};
    vector<int>mapping{3,5,4,6,2,7,9,8,0,1};
    vector<string> result = strangeSort(nums,mapping);
    
    for(string s : result){
        cout<<s<<" ";
    }
    return 0;
}
