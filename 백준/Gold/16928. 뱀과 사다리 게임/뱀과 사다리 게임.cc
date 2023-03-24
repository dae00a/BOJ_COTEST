#include <bits/stdc++.h>

#define LAST 101

using namespace std;

int N, M;
int plane[LAST];
bool visited[LAST];
unordered_map<int, int> ladder, snake;

int solution();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    int ans = solution();

    cout << ans << "\n";

    return 0;
}

int solution() {
    int loc = 1, cnt = 0, ret = LAST;
    queue<pair<int, int>> q;

    q.push({loc, cnt});
    visited[loc] = true;

    while(!q.empty()) {
        int curLoc = q.front().first, curCnt = q.front().second;

        if(curLoc == 100)
            ret = min(ret, curCnt);

        for(int i = 1; i <= 6; i++) {
            int nextLoc = curLoc + i;

            if(nextLoc > 100 || visited[nextLoc])
                continue;
            visited[nextLoc] = true;
            
            if(ladder[nextLoc]) {
                nextLoc = ladder[nextLoc];
                visited[nextLoc] = true;
            }
            else if(snake[nextLoc]) {
                nextLoc = snake[nextLoc];
                visited[nextLoc] = true;
            }

            q.push({nextLoc, curCnt + 1});
        }

        q.pop();
    }

    return ret;
}