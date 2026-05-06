#include<bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int>> &board, int r, int c, int n){
    for(int i = 0; i < n; i++) if(board[i][c]) return false;

    for(int i = r, j = c; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]) return false;
    }

    for(int i = r, j = c; i >= 0 && j < n; i--, j++){
        if(board[i][j]) return false;
    }

    return true;
}
bool solve(int n, vector<vector<int>> &board, int row){
    if(row >= n) return true;

    for(int i = 0; i < n; i++){
        if(safe(board, row, i, n)){
            board[row][i] = 1;
            if(solve(n, board, row+1)) return true;
            board[row][i] = 0;
        }
    }

    return false;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> board(n, vector<int> (n, 0));
    solve(n, board, 0);

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            if(board[i][k] == 1) cout<<" Q ";
            else cout<<" . ";
        }
        cout<<endl;
    }

    return 0;
}
