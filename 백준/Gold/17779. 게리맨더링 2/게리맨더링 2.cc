#include <bits/stdc++.h>

using namespace std;

int N, A[21][21];
bool visited[21][21];
int ans = 20 * 20 * 100;
const pair<int, int> d[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, };

void bfs(int r, int c);
void grouping5(int x, int y, int d1, int d2);
int grouping(int x, int y, int d1, int d2);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) 
            cin >> A[i][j];
    }

    for(int x = 1; x <= N; x++) {
        for(int y = 1; y <= N; y++) {
            for(int d1 = 1; d1 < N; d1++) {
                for(int d2 = 1; d2 < N; d2++) {
                    if(x + d1 + d2 > N)
                        continue;
                    if((y - d1 < 1) || (y + d2 > N))
                        continue;
                    
                    grouping5(x, y, d1, d2);

                    int diff_min_max = grouping(x, y, d1, d2);
                    if(diff_min_max < ans)
                        ans = diff_min_max;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while(!q.empty()) {
        int cur_r = q.front().first, cur_c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_r = cur_r + d[i].first, new_c = cur_c + d[i].second;

            if(visited[new_r][new_c])
                continue;
            q.push({new_r, new_c});
            visited[new_r][new_c] = true;
        }
    }
}

void grouping5(int x, int y, int d1, int d2) {
    for(int i = 1; i <= N; i++)
        memset(visited[i], false, N + 1);

    for(int i = 0; i <= d2; i++) {
        visited[x+i][y+i] = true;
        visited[x+d1+i][y-d1+i] = true;
    }
    for(int i = 0; i <= d1; i++) {
        visited[x+i][y-i] = true;
        visited[x+d2+i][y+d2-i] = true;
    }
    for(int i = 0; i < d2; i++)
        bfs(x+i+1, y+i);
    for(int i = 0; i < d1; i++)
        bfs(x+i+1, y-i);
}

int grouping(int x, int y, int d1, int d2) {
    int num[6];
    memset(num, 0, 6 * sizeof(int));

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            int i = 5;

            if(visited[r][c]) {
                num[5] += A[r][c];
                continue;
            }

            if(r < x + d1 && c <= y)
                i = 1;
            else if(r <= x + d2 && y < c)
                i = 2;
            else if(x + d1 <= r && c < y - d1 + d2)
                i = 3;
            else if(x + d2 < r && y - d1 + d2 <= c)
                i = 4;
            
            num[i] += A[r][c];
        }
    }

    int minNum = num[1], maxNum = num[1];
    for(int i = 2; i < 6; i++) {
        minNum = min(minNum, num[i]);
        maxNum = max(maxNum, num[i]);
    }

    return (maxNum - minNum);
}