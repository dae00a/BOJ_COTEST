#include <bits/stdc++.h>

using namespace std;

int R, C, N;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool mineral[101][101];
int cluster[101][101];
queue<pair<int, pair<int, int>>> q;

void solve(int d, int h);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < C; j++) {
            if(s[j] == 'x')
                mineral[i][j] = true;
        }
    }

    cin >> N;
    for(int i = 0; i < N; i++) {
        int h;
        cin >> h;
        solve(i % 2, h);
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++)
            cout << (mineral[i][j] ? 'x' : '.');
        cout << "\n";
    }

    return 0;
}

void bfs(int m) {
    bool fixed = false;

    while(!q.empty()) {
        int m = q.front().first;
        int cur_r = q.front().second.first, cur_c = q.front().second.second;

        if(cur_r == R - 1)
            fixed = true;
    
        for(int i = 0; i < 4; i++) {
            int new_r = cur_r + dx[i], new_c = cur_c + dy[i];

            if(new_r < 0 || new_r >= R || new_c < 0 || new_c >= C)
                continue;
            if(!mineral[new_r][new_c] || cluster[new_r][new_c])
                continue;

            cluster[new_r][new_c] = m;
            q.push({m, {new_r, new_c}});
        }

        q.pop();
    }

    if(fixed) {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(cluster[i][j] == m) 
                    cluster[i][j] = 0;
            }
        }
    }
}

void drop() {
    int dropH[5] = {0, 101, 101, 101, 101};

    for(int j = 0; j < C; j++) {
        int add = 0;
        int block = R;
        for(int i = R - 1; i >= 0; i--) {
            if(!cluster[i][j] && mineral[i][j]) {
                block = i;
                add = 0;
            }
            else if(cluster[i][j]) {
                dropH[cluster[i][j]] = min(dropH[cluster[i][j]], block - i - 1 - add);
                //cout << block << " " << i << " " << add << " " << dropH[cluster[i][j]] << "\n";
                add++;
            }
        }   
    }

    for(int i = 1; i < 5; i++) {
        if(dropH[i] > 100)
            dropH[i] = 0;
    }

    for(int i = R - 1; i >= 0; i--) {
        for(int j = 0; j < C; j++) {
            if(cluster[i][j]) {
                mineral[i][j] = false;
                mineral[i+dropH[cluster[i][j]]][j] = true;
            }
        }   
    }
}

void solve(int d, int h) {
    int r = R - h, c = -1;

    if(d) {
        for(int i = C - 1; i >= 0; i--) {
            if(mineral[r][i]) {
                mineral[r][i] = false;
                c = i;
                break;
            }
        }
    }
    else {
        for(int i = 0; i < C; i++) {
            if(mineral[r][i]) {
                mineral[r][i] = false;
                c = i;
                break;
            }
        }
    }

    if(c >= 0) {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++)
                cluster[i][j] = 0;
        }
        cluster[r][c] = 5;

        for(int i = 0; i < 4; i++) {
            int new_r = r + dx[i], new_c = c + dy[i];
            
            if(new_r < 0 || new_r >= R || new_c < 0 || new_c >= C)
                continue;
            if(!mineral[new_r][new_c] || cluster[new_r][new_c])
                continue;
            
            q.push({i + 1, {new_r, new_c}});
            cluster[new_r][new_c] = i + 1;
            bfs(i + 1);
        }
        cluster[r][c] = 0;

        /*
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cout << cluster[i][j];
            }
            cout << "\n";
        }
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++)
                cout << (mineral[i][j] ? 'x' : '.');
            cout << "\n";
        }
        */

        drop();

        /*
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++)
                cout << (mineral[i][j] ? 'x' : '.');
            cout << "\n";
        }
        */
    }
}