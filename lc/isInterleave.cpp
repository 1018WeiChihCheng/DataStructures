//
//  main.cpp
//  isInterleave
//
//  Created by WEICHIH on 3/6/20.
//  Copyright © 2020 WEICHIH. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isInterleave(string &s1, string &s2, string &s3) {
    // write your code here
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<bool>>dp(n + 1,vector<bool>(m + 1,0));
    //dp[i][j] means: whether i characters of s1, j characters of s2 isInterleave of  i + j characters of s3?
    dp[0][0] = true;
    for(int j = 1; j <= m; j++){
        dp[0][j] = (dp[0][j - 1]) * (s2[j - 1] == s3[j - 1]);
    }
    for(int i = 1 ; i <= n; i++){
        dp[i][0] = (dp[i - 1][0]) * (s1[i - 1] == s3[i - 1]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            if(dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])){
                dp[i][j] = true;
            }
            if(dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])){
                dp[i][j] = true;
            }
        }
    }
    return dp[n][m];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout<< isInterleave(s1, s2, s3)<<endl;
    return 0;
}
