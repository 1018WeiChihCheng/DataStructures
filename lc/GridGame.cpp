//
//  main.cpp
//  GridGame
//
//  Created by WEICHIH on 2/24/20.
//  Copyright © 2020 WEICHIH. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>GridGame(vector<vector<int>>&board,int k, vector<string>&rules){
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> copyBoard(rows,vector<int>(cols,0));
    vector<int> neighbors = {0, 1, -1};
    for(int time = 0; time < k; time++){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                copyBoard[row][col] = board[row][col];
            }
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int liveNeighbors = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (copyBoard[r][c] == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }
                if(rules[liveNeighbors] == "alive"){
                    board[row][col] = 1;
                }else{
                    board[row][col] = 0;
                }
            }
        }
        
    }
    
    return board;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>>board = {{0,1,1,0},{1,1,0,0}};
    int k = 3;
    vector<string>rules = {"dead","dead","dead","alive","dead","alive","dead","dead","dead"};
    
    vector<vector<int>>result = GridGame(board, k, rules);
    
    
    return 0;
}
