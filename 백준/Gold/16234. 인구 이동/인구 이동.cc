#include <bits/stdc++.h>

using namespace std;

int N, L, R;
int country[51][51];
int visited[51][51], avg_people[2501];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

pair<int, int> bfs(int row, int col, int ally);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> L >> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cin >> country[i][j];
    }

    int answer;
    for(answer = 0; answer <= 2000; answer++) {
        bool imgrnt = false;
        for(int i = 0; i < N; i++) 
            memset(visited[i], 0, N * sizeof(int));

        int tmp = 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j]) {
                    pair<int, int> p = bfs(i, j, tmp);
                    avg_people[tmp] = p.first / p.second;
                    tmp++;

                    if(p.second > 1) 
                        imgrnt = true;
                }
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) 
                country[i][j] = avg_people[visited[i][j]];
        }

        if(!imgrnt)
            break;
    }

    cout << answer <<"\n";

    return 0;
}

pair<int, int> bfs(int row, int col, int ally) {
    pair<int, int> ret = {0, 0};
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = ally;

    while(!q.empty()) {
        int cur_row = q.front().first, cur_col = q.front().second;
        q.pop();

        ret.first += country[cur_row][cur_col];
        ret.second++;

        for(int i = 0; i < 4; i++) {
            int new_row = cur_row + dx[i], new_col = cur_col + dy[i];

            if(new_row < 0 || new_row >= N || new_col < 0 || new_col >= N)
                continue;
            if(visited[new_row][new_col])
                continue;
            int diff = abs(country[cur_row][cur_col] - country[new_row][new_col]);
            if(diff < L || diff > R)
                continue;
            
            visited[new_row][new_col] = ally;
            q.push({new_row, new_col});
        }
    }

    return ret;
}