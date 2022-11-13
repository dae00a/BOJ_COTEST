#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N;
long double simple_prob;
long double EWSN_prob[4];
bool visit[29][29];

void move_robot(int cnt, int x, int y, long double prob);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < 4; i++) {
        cin >> EWSN_prob[i];
        EWSN_prob[i] *= 0.01;
    }

    // 로봇의 출발 지점
    visit[14][14] = true;
    
    move_robot(0, 14, 14, 1);

    cout.precision(10);
    cout << 1 - simple_prob << "\n";

    return 0;
}

void move_robot(int cnt, int x, int y, long double prob) {
    int new_x, new_y;
    
    // 최대 이동 횟수 도달
    if(cnt == N) {
        return ;
    }

    // 동서남북 이동
    for(int i = 0; i < 4; i++) {
        // 해당 방향으로 이동할 확률이 0인 경우
        if(!EWSN_prob[i]) {
            continue;
        }
        
        // 이동할 위치
        new_x = x + dx[i];
        new_y = y + dy[i];
        
        // 재방문인 경우
        if(visit[new_x][new_y]) {
            simple_prob += prob * EWSN_prob[i];
        }
        // 미방문인 경우
        else {
            visit[new_x][new_y] = true;
            move_robot(cnt + 1, new_x, new_y, prob * EWSN_prob[i]);
            visit[new_x][new_y] = false;
        }
    }
}