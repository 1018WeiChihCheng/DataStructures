//
//  main.cpp
//  editDistance
//
//  Created by WEICHIH on 3/6/20.
//  Copyright © 2020 WEICHIH. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int min_(int state1, int state2, int state3){
    return min(min(state1,state2),state3);
}
int minDistance(string &word1, string &word2) {
    // write your code here
    int n = word1.size();
    int m = word2.size();
    
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }
    vector<vector<int>>dp(n + 1,vector<int>(m + 1,0));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0){
                dp[i][j] = j;
            }
            if(j == 0){
                dp[i][j] = i;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int index1 = i - 1;
            int index2 = j - 1;
            if(word1[index1]!=word2[index2]){
                //insert,replace,delete
                dp[i][j] = min_(dp[i][j - 1]+ 1, dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1);
            }
            else{
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[n][m];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s1 = "horse";
    string s2 = "ros";
    cout<<minDistance(s1, s2)<<endl;
    return 0;
}
