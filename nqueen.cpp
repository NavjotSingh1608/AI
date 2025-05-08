#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<bool> col,diag1,diag2;

void printB(int N){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

bool solve(int row,int n){
    if(row == n) return true;

    for(int c = 0; c < n; c++){
        if(!col[c] && !diag1[row - c + n - 1] && !diag2[row+c]){
            board[row][c] = 1;
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;

            if(solve(row+1,n)) return true;

            board[row][c] = 0;
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }

    return false;
}

int main(){
    int n = 4;

    board.assign(n,vector<int> (n,0));
    col.assign(n,false);
    diag1.assign(2*n-1,false);
    diag2.assign(2*n-1,false);

    if(solve(0,n)){
        printB(n);
    }else{
        cout << "No soln" << endl;
    }
}