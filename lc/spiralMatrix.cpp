//
//  main.cpp
//  spiralMatrix
//
//  Created by WEICHIH on 2/26/20.
//  Copyright © 2020 WEICHIH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool isPrime(int num){
    int k = sqrt(num);
    if(num <= 1){
        return false;
    }
    if(num >= 2 && num <=3){
        return true;
    }
    if(num % 6 != 1 && num % 6 != 5){
        return false;
    }
    for(int i = 5; i <=k; i+=6){
        if(num % i == 0 || num %(i + 2) == 0){
            return false;
        }
    }
    return true;
}
void spiralMatrix(vector<vector<int>>&A,int l,int row,int col, int count,vector<int>&res){
    if(count == 0){
        return;
    }
    //left 2 right
    for(row = l,col = l; col <= A[0].size() - 1 - l && count > 0;col++){
        if(isPrime(A[row][col])){
            res.push_back(A[row][col]);
        }
        count--;
    }
    //up 2 down
    for(row = l + 1, col = A[0].size() - 1 - l; row <= A.size() - 1 - l && count > 0; row++){
        if(isPrime(A[row][col])){
            res.push_back(A[row][col]);
        }
        count--;
    }
    //right 2 left
    for(row = A.size() - 1 - l, col = A[0].size() - 2 - l; col >= l && count > 0; col--){
        if(isPrime(A[row][col])){
            res.push_back(A[row][col]);
        }
        count--;
    }
    //down 2 up
    for(row = A.size() - 2 - l, col = l; row >= l + 1 && count > 0 ; row--){
        if(isPrime(A[row][col])){
            res.push_back(A[row][col]);
        }
        count--;
    }
    spiralMatrix(A, l + 1, row, col, count, res);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>>A = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int>res;
    int count = A.size() * A[0].size();
    spiralMatrix(A, 0, 0, 0, count, res);
    for(int n : res){
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}
