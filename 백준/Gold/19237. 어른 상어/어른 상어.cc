#include <bits/stdc++.h>

#define MAX_N 20

using namespace std;

typedef struct NODE {
    int direction[5][4], now_direction, x, y;
    bool inMatrix;
} NODE;

int N, M, k, leftShark;
int dy[] = {0, -1, 1, 0, 0}, dx[] = {0, 0, 0, -1, 1};
vector<vector<pair<int, int>>> matrix(21, vector<pair<int, int>> (21));
vector<NODE> sharkInfo(MAX_N * MAX_N + 1);

void solution();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M >> k;
    leftShark = M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            matrix[i][j].first = tmp;
            sharkInfo[tmp].y = i;
            sharkInfo[tmp].x = j;
            sharkInfo[tmp].inMatrix = true;
        }
    }

    for(int i = 1; i <= M; i++) {
        int tmp;
        cin >> tmp;
        sharkInfo[i].now_direction = tmp;
    }

    for(int i = 1; i <= M; i++) {
        for(int cur_direct = 1; cur_direct <= 4; cur_direct++) {
            for(int j = 0; j < 4; j++) {
                int next_direction;
                cin >> next_direction;            
                sharkInfo[i].direction[cur_direct][j] = next_direction;
            }
        }
    }

    int sec = 0;
    while(sec <= 1000) {
        solution();
        sec++;
        if(leftShark <= 1)
            break;
    }
    
    cout << (sec > 1000 ? -1 : sec) << "\n";

    return 0;
}

void solution() {
    int visited[N+1][N+1];
    for(int i = 0; i <= N; i++)
        memset(visited[i], 0, (N + 1) * sizeof(int));

    for(int i = 1; i <= M; i++) {
        if(!sharkInfo[i].inMatrix)
            continue;
        
        matrix[sharkInfo[i].y][sharkInfo[i].x].second = k;
        bool moved = false;

        for(int j = 0; j < 4; j++) {
            int new_direction = sharkInfo[i].direction[sharkInfo[i].now_direction][j];
            int new_y = sharkInfo[i].y + dy[new_direction];
            int new_x = sharkInfo[i].x + dx[new_direction];
        
            if(new_y <= 0 || new_y > N || new_x <= 0 || new_x > N)
                continue;
            if(matrix[new_y][new_x].first > 0)
                continue;
            moved = true;

            if(visited[new_y][new_x]) {
                sharkInfo[i].inMatrix = false;
                leftShark--;
            }
            else {
                visited[new_y][new_x] = i;
                sharkInfo[i].y = new_y;
                sharkInfo[i].x = new_x;
                sharkInfo[i].now_direction = new_direction;
            }
            break;
        }

        if(moved)
            continue;
        for(int j = 0; j < 4; j++) {
            int new_direction = sharkInfo[i].direction[sharkInfo[i].now_direction][j];
            int new_y = sharkInfo[i].y + dy[new_direction];
            int new_x = sharkInfo[i].x + dx[new_direction];
        
            if(new_y <= 0 || new_y > N || new_x <= 0 || new_x > N)
                continue;
            if(matrix[new_y][new_x].first != i)
                continue;

            sharkInfo[i].y = new_y;
            sharkInfo[i].x = new_x;
            sharkInfo[i].now_direction = new_direction;
            break;
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(matrix[i][j].second)
                matrix[i][j].second--;
            if(matrix[i][j].second <= 0)
                matrix[i][j].first = 0;
        }
    }

    for(int i = 1; i <= M; i++) {
        if(!sharkInfo[i].inMatrix)
            continue;
        matrix[sharkInfo[i].y][sharkInfo[i].x].first = i;
    }
}