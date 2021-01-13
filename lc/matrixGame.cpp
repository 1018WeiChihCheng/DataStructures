//
//  main.cpp
//  matrixGame
//
//  Created by WEICHIH on 2/25/20.
//  Copyright © 2020 WEICHIH. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int matrixGame(vector<vector<int>>&matrix){
    int n = matrix.size();
    if(n == 0){
        return 0;
    }
    int m = matrix[0].size();
    vector<int>maxNum(m,INT_MIN);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] > maxNum[j]){
                maxNum[j] = matrix[i][j];
            }
        }
    }
    sort(maxNum.begin(),maxNum.end(),greater<int>());
    int scoreT = 0, scoreJ = 0;
    for(int i = 0; i < maxNum.size(); i++){
        if(i%2 == 0){
            scoreT += maxNum[i];
        }else{
            scoreJ += maxNum[i];
        }
    }
    cout<<"T:"<<scoreT<<" J:"<<scoreJ<<endl;
    return scoreT - scoreJ;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //case1
    vector<vector<int>>matrix = {
        {3,7,5,3,4,5},
        {4,5,2,6,4,5},
        {7,4,9,7,8,3}
    };
    //case2
    //5,9,6,9,9,8,5,9
    vector<vector<int>>matrix2 = {
        {5,7,6,2,8,4,4,8},
        {2,7,4,5,9,8,4,2},
        {5,4,2,9,8,3,3,4},
        {4,9,3,4,6,8,4,9},
        {1,4,6,2,9,3,5,6}
    };
    cout<<matrixGame(matrix2)<<endl;
    return 0;
}
