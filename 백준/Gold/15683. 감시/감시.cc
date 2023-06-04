#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef struct NODE {
    int row, col, type;
} NODE;

int N, M;
int office[8][8];
bool check[8][8][8];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<NODE> cctv;
int min_blind = 65;

void dfs(int cnt);
bool range(int row, int col);
void check_office(int cnt, int row, int col, int dir);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> office[i][j];
            if(office[i][j] > 0 && office[i][j] < 6) 
                cctv.push_back({i, j, office[i][j]});
        }
    }

    dfs(0);

    cout << min_blind << "\n";

    return 0;
}

void dfs(int cnt) {
    // cnt가 cctv의 개수와 동일한 경우
    if(cnt == cctv.size()) {
        bool blind_spot;
        int blind = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                blind_spot = true;

                for(int k = 0; k < cctv.size(); k++) {
                    if(check[k][i][j]) {
                        blind_spot = false;
                        break;
                    }
                }

                // 해당 위치가 사각지대이고 빈 공간인 경우
                if(blind_spot && !office[i][j])
                    blind++;
            }
        }

        if(min_blind > blind)
            min_blind = blind;
        
        return;
    }

    /* cnt 번째 cctv의 방향 설정
     * 1번: 상,하,좌,우 4방향
     * 2번: 상하, 좌우 2방향
     * 3번: 상,하,좌,우 4방향
     * 4번: 상,하,좌,우 4방향
     * 5번: 상하좌우 1방향
     */

    for(int i = 0; i < 4; i++) {
        if(cctv[cnt].type == 5 && i == 1)
            break;
        if(cctv[cnt].type == 2 && i == 2)
            break;

        // cctv 사각지대 초기화
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                check[cnt][j][k] = false;
            }
        }
        
        if(cctv[cnt].type == 1) 
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i);
        else if(cctv[cnt].type == 2) {
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i);
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i+2);
        }
        else if(cctv[cnt].type == 3) {
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i);
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, (i+1)%4);
        }
        else if(cctv[cnt].type == 4) {
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i);
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, (i+1)%4);
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, (i+2)%4);
        }
        else if(cctv[cnt].type == 5) {
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i);
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i+1);
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i+2);
            check_office(cnt, cctv[cnt].row, cctv[cnt].col, i+3);
        }

        dfs(cnt + 1);
    }
}

bool range(int row, int col) {
    return (row < N && row >= 0 && col < M && col >= 0);
}

void check_office(int cnt, int row, int col, int dir) {
    // 벽을 만나지 않거나 범위를 벗어나지 않는 동안 감시 영역 확장
    while(office[row][col] < 6 && range(row, col)) {
        check[cnt][row][col] = true;
        row += dy[dir];
        col += dx[dir];
    }
}