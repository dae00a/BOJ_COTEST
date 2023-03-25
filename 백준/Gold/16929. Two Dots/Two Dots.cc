#include <bits/stdc++.h>

using namespace std;

typedef struct DOT {
    int from, row, col;
} DOT;

const int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int N, M;
char dots[51][51];

bool findCycle(int r, int c, char t);
bool solution();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    string answer;

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++)
            dots[i][j] = s[j];
    }

    if(solution())
        answer = "Yes\n";
    else
        answer = "No\n";

    cout << answer; 

    return 0;
}

bool findCycle(int r, int c, char t) {
    bool visited[51][51], cycle = false;
    queue<DOT> q;

    for(int i = 0; i < 50; i++)
        memset(visited[i], 0, 50 * sizeof(bool));
    
    q.push({-1, r, c});

    while(!q.empty()) {
        int cur_r = q.front().row, cur_c = q.front().col;

        for(int i = 0; i < 4; i++) {
            int new_r = cur_r + dr[i], new_c = cur_c + dc[i];

            if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M) 
                continue;
            if(i == q.front().from || dots[new_r][new_c] != t)
                continue;
            
            if(visited[new_r][new_c])
                cycle = true;
            else {
                visited[new_r][new_c] = true;
                q.push({(i + 2) % 4, new_r, new_c});
            }
        }

        q.pop();
    }

    return cycle;
}

bool solution() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(findCycle(i, j, dots[i][j]))
                return true;
        }
    }

    return false;
}