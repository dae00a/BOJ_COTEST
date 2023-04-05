#include <bits/stdc++.h>

using namespace std;

typedef pair<pair<int, int>, pair<int, int>> P;

int W, H;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool visited[101][101][4];
int mirror[101][101][4]; 
vector<string> v(101);
vector<pair<int, int>> laser;
queue<P> q;

int bfs();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> W >> H;
    for(int i = 0; i < H; i++) {
        cin >> v[i];
        for(int j = 0; j < v[i].length(); j++) {
            if(v[i][j] == 'C')
                laser.push_back({i, j});
        }
    }
        
    int ans = bfs();
    cout << ans << "\n";

    return 0;
}

int bfs() {
    q.push({{0, -1}, {laser[0].first, laser[0].second}});
    for(int i = 0; i < 4; i++) {
        visited[laser[0].first][laser[0].second][i] = true;
        mirror[laser[0].first][laser[0].second][i] = 0;
    }
        
    while(!q.empty()) {
        int cnt = q.front().first.first, direction = q.front().first.second;
        int cur_x = q.front().second.first, cur_y = q.front().second.second;
        q.pop();
 
        for(int i = 0; i < 4; i++) {
            int new_x = cur_x + dx[i], new_y = cur_y + dy[i], new_cnt = cnt;

            if(new_x < 0 || new_x >= H || new_y < 0 || new_y >= W)
                continue;
            if(v[new_x][new_y] == '*')
                continue;
            
            if(i != direction)
                new_cnt++;

            if(visited[new_x][new_y][i]) {
                if(new_cnt < mirror[new_x][new_y][i]) {
                    mirror[new_x][new_y][i] = new_cnt;
                    q.push({{new_cnt, i}, {new_x, new_y}});
                }
            }
            else {
                visited[new_x][new_y][i] = true;
                mirror[new_x][new_y][i] = new_cnt;
                q.push({{new_cnt, i}, {new_x, new_y}});
            }
        }
    }

    int ret = 10001;
    for(int i = 0; i < 4; i++) {
        if(visited[laser[1].first][laser[1].second][i]) {
            if(mirror[laser[1].first][laser[1].second][i] < ret)
                ret = mirror[laser[1].first][laser[1].second][i];
        }
    }
    return ret - 1;
}