//
//  main.cpp
//  rotateString
//
//  Created by WEICHIH on 2/25/20.
//  Copyright © 2020 WEICHIH. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void reverse(string arr, int start, int end){
    while(start<end){
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
string rotate(string arr, vector<int>shift, vector<int>dir){
    int total = 0;
    for(int i = 0; i< shift.size(); i++){
        if(dir[i] == 1){
            total += shift[i];
        }else{
            total -= shift[i];
        }
    }
    bool isRight = false;
    if(total > 0){
        isRight = true;
    }
    total = abs(total) % arr.size();
    
    int n = arr.size();
    string res = "";
    if(isRight){
        //shift right.
        string leftSub = arr.substr(0, n - total);
        string rightSub = arr.substr(n - total);
        res = rightSub + leftSub;
    }else{
        //shift left
        string leftSub = arr.substr(0,total);
        string rightSub = arr.substr(total);
        res = rightSub + leftSub;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "qwertyudsf";
    vector<int>shift = {2,1,2};
    vector<int>dir = {1,0,1};
    
    string result = rotate(s,shift, dir);
    cout<<result<<endl;
    return 0;
}
