//
//  main.cpp
//  sharePurchase
//
//

#include <iostream>
#include <vector>
using namespace std;
int sharePurchase(string str){
    int n = str.size();
    const int sizeOfString = 3;
    if(n < sizeOfString){
        return 0;
    }
    int l = 0, r = 0;//left and right pointer
    int a = 0, b = 0, c = 0;//counter for a , b, c
    int result = 0;//total substring number
    while(r < n){
        if(str[r] == 'A'){
            a++;
        }else if(str[r] == 'B'){
            b++;
        }else if(str[r] == 'C'){
            c++;
        }
        //ex: "ABC|DEA"
        while(((a*b*c)!=0) && l <= n - sizeOfString){
            result += ((n - 1) - r + 1);
            if(str[l] == 'A'){
                a--;
            }else if(str[l] == 'B'){
                b--;
            }else if(str[l] == 'C'){
                c--;
            }
            l++;
        }
        r++;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> caseAry = {"ABC","ABCCBA","ACBA","ABBCZBAC"};
    for(string s : caseAry){
            cout<<sharePurchase(s)<<endl;
    }
    return 0;
}
