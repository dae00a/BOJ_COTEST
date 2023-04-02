#include <bits/stdc++.h>

using namespace std;

int R, C;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool water[1501][1501];
int swan[2][1501][1501];
queue<pair<int, pair<int, int>>> wq;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> sq[2];

void bfs();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int tmp = 0;
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < C; j++) {
            if(s[j] == '.') {
                water[i][j] = true;
                wq.push({0, {i, j}});
            }
            else if(s[j] == 'L') {
                water[i][j] = true;
                sq[tmp].push({0, {i, j}});
                swan[tmp][i][j] = 1;
                tmp++;
            }
        }
    }

    bfs();

    return 0;
}

void bfs() {
    for(int d = 0; !wq.empty(); d++) {
        int day, cur_r ,cur_c;

        day = 0;
        while(day <= d) {
            day = sq[0].top().first;
            cur_r = sq[0].top().second.first;
            cur_c = sq[0].top().second.second;

            if(d < day)
                break;

            sq[0].pop();

            for(int i = 0; i < 4; i++) {
                int new_r = cur_r + dx[i], new_c = cur_c + dy[i];
                
                if(new_r < 0 || new_r >= R || new_c < 0 || new_c >= C)
                    continue;
                if(swan[1][new_r][new_c]) {
                    cout << swan[1][new_r][new_c] << "\n";
                    return ;
                }
                if(swan[0][new_r][new_c])
                    continue;
                
                if(water[new_r][new_c])
                    sq[0].push({day, {new_r, new_c}});
                else
                    sq[0].push({day + 1, {new_r, new_c}});
                swan[0][new_r][new_c] = day + 1;
            }
        }

        day = 0;
        while(day <= d) {
            day = sq[1].top().first;
            cur_r = sq[1].top().second.first;
            cur_c = sq[1].top().second.second;

            if(d < day)
                break;

            sq[1].pop();

            for(int i = 0; i < 4; i++) {
                int new_r = cur_r + dx[i], new_c = cur_c + dy[i];
                
                if(new_r < 0 || new_r >= R || new_c < 0 || new_c >= C)
                    continue;
                if(swan[0][new_r][new_c]) {
                    cout << swan[0][new_r][new_c] << "\n";
                    return ;
                }
                if(swan[1][new_r][new_c])
                    continue;
                
                if(water[new_r][new_c])
                    sq[1].push({day, {new_r, new_c}});
                else
                    sq[1].push({day + 1, {new_r, new_c}});
                swan[1][new_r][new_c] = day + 1;
            }
        }

        day = 0;
        while(day <= d) {
            day = wq.front().first;
            cur_r = wq.front().second.first;
            cur_c = wq.front().second.second;

            if(d < day)
                break;

            for(int i = 0; i < 4; i++) {
                int new_r = cur_r + dx[i], new_c = cur_c + dy[i];
                
                if(new_r < 0 || new_r >= R || new_c < 0 || new_c >= C)
                    continue;
                if(water[new_r][new_c])
                    continue;
                water[new_r][new_c] = true;
                wq.push({day + 1, {new_r, new_c}});
            }

            wq.pop();
        }
    }   
}