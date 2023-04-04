#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> P;

int T, h, w;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char _map[102][102];

vector<vector<int>> bfs(int opened, int x, int y);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> T;
    while(T--) {
        int tmp = 1, x[3] = {0, }, y[3]= {0, };
        
        cin >> h >> w;
        for(int i = 1; i <= h; i++) {
            string s;
            cin >> s;
            for(int j = 1; j <= w; j++) {
                _map[i][j] = s[j-1];

                if(s[j-1] == '$') {
                    x[tmp] = i, y[tmp] = j;
                    tmp++;
                }
            }
        }
        for(int i = 0; i <= w + 1; i++) {
            _map[0][i] = '.';
            _map[h+1][i] = '.';
        }
        for(int i = 0; i <= h + 1; i++) {
            _map[i][0] = '.';
            _map[i][w+1] = '.';
        }

        vector<vector<vector<int>>> v(3, vector<vector<int>>(h+2, vector<int>(w+2)));
    
        for(int i = 0; i < 3; i++)
            v[i] = bfs(0, x[i], y[i]);

        int minOpened = 10000;
        for(int i = 0; i <= h + 1; i++) {
            for(int j = 0; j <= w + 1; j++) {
                int sum = 0;
                for(int k = 0; k < 3; k++)
                    sum += v[k][i][j];

                if(i > 0 && i <= h && j > 0 && j <= w && !sum)
                    continue;
                if(_map[i][j] == '#')
                    sum -= 2;
                minOpened = min(minOpened, sum);
            }
        }

        cout << minOpened << "\n";
    }

    return 0;
}

vector<vector<int>> bfs(int opened, int x, int y) {
    bool visited[102][102];
    vector<vector<int>> ret(h+2, vector<int>(w+2, 0));
    priority_queue<P, vector<P>, greater<P>> pq;

    for(int i = 0; i < 102; i++) 
        memset(visited[i], 0, 102);

    pq.push({opened, {x, y}});
    visited[x][y] = true;

    while(!pq.empty()) {
        int opened = pq.top().first;
        int cur_x = pq.top().second.first, cur_y = pq.top().second.second;
        pq.pop();

        ret[cur_x][cur_y] = opened;
        
        for(int i = 0; i < 4; i++) {
            int new_x = cur_x + dx[i], new_y = cur_y + dy[i];

            if(new_x < 0 || new_x > h + 1 || new_y < 0 || new_y >  w + 1)
                continue;
            if(_map[new_x][new_y] == '*' || visited[new_x][new_y])
                continue;
            
            if(_map[new_x][new_y] == '#')
                pq.push({opened + 1, {new_x, new_y}});
            else
                pq.push({opened, {new_x, new_y}});
            visited[new_x][new_y] = true;
        }        
    }

    return ret;
}