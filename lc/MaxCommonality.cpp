//
//  main.cpp
//  MaxCommality
//
//  Created by WEICHIH on 2/24/20.
//  Copyright © 2020 WEICHIH. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int findMaxCommonality(string &s){
    vector<int>count(26,0);
    for(char c : s){
        count[c - 'a']++;
    }
    int curr = 0, result = INT_MIN;
    for(char c : s){
        if(count[c - 'a'] > 1){//can seperate this char to left and right.
            curr++;
            count[c - 'a'] -= 2;
        }
        else if(count[c - 'a'] == 0){//now character c belongs to left.
            curr--;
        }
        else{//count[c] == 1, skip to the next char.
            count[c - 'a']--;
        }
        result = max(curr,result);
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "aabbbbaa";
    cout<<findMaxCommonality(s)<<endl;
    return 0;
}
