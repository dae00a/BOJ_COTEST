#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

int N, M, x, y, k;
int dice[7], dice_map[21][21];

void east();
void west();
void north();
void south();

void (*funcptr[])() = {east, west, north, south};

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M >> x >> y >> k;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> dice_map[i][j];
        }
    }

    int direct;
    while(k--) {
        cin >> direct;

        int new_x = x + dx[direct-1], new_y = y + dy[direct-1];
        
        // 범위 초과
        if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
            continue;

        // 주사위 이동
        x = new_x, y = new_y;
        (*funcptr[direct-1])();

        cout << dice[1] << "\n";

        // 지도 값이 0이 아닌 경우
        if(dice_map[new_x][new_y]) {
            dice[2] = dice_map[new_x][new_y];
            dice_map[new_x][new_y] = 0;
        } 
        else 
            dice_map[new_x][new_y] = dice[2];
    }

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