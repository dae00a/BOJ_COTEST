#include <bits/stdc++.h>

using namespace std;

int N, M;
int table[9][9], answer, territory;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
vector<pair<int, int>> virous;

void bfs(int area);
void dfs(int cnt);
void solution();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> table[i][j];
            if(table[i][j] != 1)
                territory++;
            if(table[i][j] == 2)
                virous.push_back({i, j});
        }   
    }

    solution();

    cout << answer << "\n";

    return 0;
}

void bfs(int area) {
    bool virous_visited[N][M];
    for(int i = 0; i < N; i++) 
        memset(virous_visited[i], 0, M * sizeof(bool));
    
    queue<pair<int, int>> q;
    int vsize = virous.size();
    for(int i = 0; i < vsize; i++) {
        int row = virous[i].first, col = virous[i].second;
        q.push({row, col});
        virous_visited[row][col] = true;
    }

    while(!q.empty()) {
        int cur_row = q.front().first, cur_col = q.front().second;
        area--;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_row = cur_row + dr[i], new_col = cur_col + dc[i];

            if(new_row < 0 || new_row >= N || new_col < 0 || new_col >= M)
                continue;
            if(virous_visited[new_row][new_col] || table[new_row][new_col])
                continue;
            
            virous_visited[new_row][new_col] = true;
            q.push({new_row, new_col});
        }
    }

    answer = max(answer, area);
}

void dfs(int cnt, int next) {
    if(cnt == 3) {
        bfs(territory - 3);
        return ;
    }

    for(int i = next; i < N * M; i++) {
        int row = i / M, col = i % M;
        if(table[row][col]) 
            continue;
        table[row][col] = 1;
        dfs(cnt + 1, i + 1);
        table[row][col] = 0;
    }
}

void solution() {
    dfs(0, 0);
}