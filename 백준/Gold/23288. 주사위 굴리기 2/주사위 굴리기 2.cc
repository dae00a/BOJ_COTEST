#include <bits/stdc++.h>

using namespace std;

const int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};

int N, M, K;
int dice[7] = {0, 1, 6, 4, 3, 5, 2}, dice_map[21][21];
bool visited[21][21];

void east();
void west();
void north();
void south();

void (*funcptr[])() = {east, north, west, south};
int bfs(int y, int x);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++)
            cin >> dice_map[i][j];
    }

    int direct = 0, y = 1, x = 1, answer = 0;
    while(K--) {
        int new_y = y + dy[direct], new_x = x + dx[direct];
        
        // 범위 초과, 반대 방향 설정
        if(new_y <= 0 || new_y > N || new_x <= 0 || new_x > M) {
            direct = (direct + 2) % 4;
            new_y = y + dy[direct]; 
            new_x = x + dx[direct];
        }

        // 주사위 이동
        y = new_y; x = new_x;
        (*funcptr[direct])();

        // 점수 획득
        answer += bfs(y, x);

        // 주사위 아랫면과 칸 비교
        if(dice[2] > dice_map[y][x])
            direct = (direct + 3) % 4;
        else if(dice[2] < dice_map[y][x])
            direct = (direct + 1) % 4;
    }

    cout << answer << "\n";

    return 0;
}

void east() {
    int up = dice[1], down = dice[2], left = dice[3], right = dice[4];
    dice[1] = left; dice[2] = right; dice[3] = down; dice[4] = up;
}
void west() {
    int up = dice[1], down = dice[2], left = dice[3], right = dice[4];
    dice[1] = right; dice[2] = left; dice[3] = up; dice[4] = down;
}
void north() {
    int up = dice[1], down = dice[2], front = dice[5], rear = dice[6];
    dice[1] = front; dice[2] = rear; dice[5] = down; dice[6] = up;
}
void south() {
    int up = dice[1], down = dice[2], front = dice[5], rear = dice[6];
    dice[1] = rear; dice[2] = front; dice[5] = up; dice[6] = down;
}

int bfs(int y, int x) {
    for(int i = 0; i <= 20; i++)
        memset(visited[i], false, 21);

    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while(!q.empty()) {
        int cur_y = q.front().first, cur_x = q.front().second;
        q.pop();
        cnt++;

        for(int i = 0; i < 4; i++) {
            int new_y = cur_y + dy[i], new_x = cur_x + dx[i];

            if(new_y <= 0 || new_y > N || new_x <= 0 || new_x > M)
                continue;
            if(visited[new_y][new_x] || (dice_map[new_y][new_x] != dice_map[y][x]))
                continue;

            visited[new_y][new_x] = true;
            q.push({new_y, new_x});
        }
    }

    return cnt * dice_map[y][x];
}