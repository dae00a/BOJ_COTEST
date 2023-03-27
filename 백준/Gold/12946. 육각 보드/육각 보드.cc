#include <bits/stdc++.h>

using namespace std;

int N;
int dx[6] = {-1, -1, 0, 1, 1, 0}, dy[6] = {0, 1, 1, 0, -1, -1}, ans;
char board[51][51], color[51][51];

void dfs(int x, int y, int c);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < N; j++) 
            board[i][j] = s[j];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 'X' && !color[i][j])
                dfs(i, j, 1);
        }
    }

    cout << ans << "\n";

    return 0;
}

void dfs(int x, int y, int c) {
    color[x][y] = c;
    ans = max(ans, 1);

    for(int i = 0; i < 6; i++) {
        int new_x = x + dx[i], new_y = y + dy[i];
        
        if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= N)
            continue;
        if(board[new_x][new_y] == 'X') {
            if(!color[new_x][new_y]) {            
                dfs(new_x, new_y, 3 - c);
                ans = max(ans, 2);
            }
            else if(color[new_x][new_y] == c){
                cout << "3\n";
                exit(0);
            }
        }    
    }
}