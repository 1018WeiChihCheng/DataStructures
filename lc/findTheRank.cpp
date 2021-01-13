//
//  main.cpp
//  findTheRank
//

#include <iostream>
#include <vector>
using namespace std;
bool CmpPair(pair<int, int>p1,pair<int, int>p2){
    return p1.first > p2.first;
}
int findTheRank(vector<vector<int>>A,int rank){
    int n = A.size();
    if(n < rank || n == 0){
        return -1;
    }
    int m = A[0].size();
    
    vector<pair<int, int>>scores;
    for(int i = 0; i < n; i++){
        int score = 0;
        for(int j = 0; j < m;j++){
            score += A[i][j];
        }
        scores.push_back(pair<int,int>(score,i + 1));
    }
    stable_sort(scores.begin(), scores.end(), CmpPair);
    return scores[rank - 1].second;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix = {{79,89,15},{71,96,88},{85,89,92},{71,96,88},{71,96,99}, {71,96,88}};
    int rank = 3;
    cout<<findTheRank(matrix, rank)<<endl;
    return 0;
}
