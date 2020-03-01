//
//  main.cpp
//  decodeWays2
//

#include <iostream>
#include <vector>
using namespace std;
int numDecodings(string &s) {
    //determine with 2 digits, return 0 if invalid
    // 1 0, dp[i - 2]
    // 2 0, dp[i - 2]
    // * 0, 2*dp[i - 2]
    // 3~9 0 , return 0
    
    // 1 *, 9*dp[i - 2] (11~19) + 9*dp[i - 1] (1~9)
    // 2 *, 6*dp[i - 2] (21~26) + 9*dp[i - 1] (1~9)
    // * *, case(1 *) + case(2 *) 15*dp[i - 2] + 9*dp[i - 1]
    // 3~9 *, 9*dp[i - 1]
    
    // 1 3~9, dp[i - 2] + dp[i - 1]
    // 2 3~9, (23~26) dp[i - 2] + dp[i - 1], (27~29) dp[i - 1]
    // * 3~9, (* 3~6)2*dp[i - 2] + dp[i - 1], (* 7~9) dp[i - 2] + dp[i - 1]
    // 3~9 3~9,dp[i - 1]
    
    int n = s.size();
    const long long int MAX = 1e9 + 7;
    vector<long long int>dp(n + 1,0);
    dp[0] = 1;
    dp[1] = (s[0] == '*')? 9 : 1;
    
    for(int i = 1; i < n; i++){
        char curr = s[i];
        int index = i + 1;
        if(curr == '0'){
            if(s[i - 1] == '1' || s[i - 1] == '2'){
                dp[index] = dp[index - 2];
            }
            if(s[i - 1] == '*'){
                dp[index] = 2 * dp[index - 2];
            }
            if(s[i - 1] == '0' || s[i - 1] > '3'){
                return 0;
            }
        }
        else if(curr == '*'){
            if(s[i - 1] == '1'){
                dp[index] = dp[index - 2] * 9 + dp[index - 1] * 9;
            }
            else if(s[i - 1] == '2'){
                dp[index] = dp[index - 2] * 6 + dp[index - 1] * 9;
            }
            else if(s[i - 1] == '*'){
                dp[index] = dp[index - 2] * 15 + dp[index - 1] * 9;
            }
            else{
                dp[index] = dp[index - 1] * 9;
            }
        }
        else{
            //curr <=3 && curr <=9
            if(s[i - 1] == '1'){
                dp[index] = dp[index - 1] + dp[index - 2];
            }
            else if(s[i - 1] == '2'){
                if(curr <= '6'){
                    dp[index] = dp[index - 2] + dp[index - 1];
                }else{
                    dp[index] = dp[index - 1];
                }
            }
            else if(s[i - 1] == '*'){
                if(curr <= '6'){
                    dp[index] = dp[index - 1] + 2 * dp[index - 2];
                }else{
                    dp[index] = dp[index - 1] + dp[index - 2];
                }
            }else{
                dp[index] = dp[index - 1];
            }
        }
        dp[index] %= MAX;
    }
    return dp[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string input = "**1**";
    cout<<"decode ways:"<<numDecodings(input)<<endl;
    return 0;
}
