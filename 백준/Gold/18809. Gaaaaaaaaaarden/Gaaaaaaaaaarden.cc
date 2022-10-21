#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct NODE {
    int row, col;
} NODE;

int N, M, G, R;
int garden[50][50];
NODE loc[10], loc_G[10], loc_R[10];
int new_arr[10];
bool spread[50][50];
const int mov[4] = {1, 0, -1, 0};
int max_flower;

// 배양액 뿌릴 수 있는 땅 中 초록, 빨강 배양액 땅 순열 선택
void combination(int cnt, int next);
void comb_GR(int cnt, int next);
void bfs();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M >> G >> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) 
            cin >> garden[i][j];
    }

    combination(0, 0);

    cout << max_flower << "\n";

    return 0;
}

void combination(int cnt, int next) {
    int row, col;
    NODE tmp;

    // 배양액 뿌릴 땅 선택한 경우
    if(cnt == G + R) {
        // 선택된 땅 중 초록, 빨강 배양액 뿌릴 땅 선택
        comb_GR(0, 0);
    }

    for(int i = next; i < N * M; i++) {
        row = i / M; col = i % M;
        
        // 해당 영역이 배양이 뿌려질 수 있는 경우
        if(garden[row][col] == 2) {
            // 해당 영역에 배양액이 뿌려지지 않은 경우
            if(!spread[row][col]) {
                tmp.row = row; tmp.col = col;
                loc[cnt] = tmp;
                spread[row][col] = true;
                combination(cnt + 1, i + 1);
                spread[row][col] = false;
            }
        }
    }
}

void comb_GR(int cnt, int next) {
    if(cnt == G) {
        for(int i = 0, j = 0, k = 0; i < G + R; i++) {
            if(j < G && i == new_arr[j]) {
                loc_G[j] = loc[i];
                j++;
            }
            else {
                loc_R[k] = loc[i];
                k++;
            }
        }

        bfs();
    }

    for(int i = next; i < G + R; i++) {
        new_arr[cnt] = i;
        comb_GR(cnt + 1, i + 1);
    }
}

void bfs() {
    int new_r, new_c;
    int flower = 0, sec = 0;
    int visit_G[50][50], visit_R[50][50];
    NODE tmp;
    queue<NODE> GQ, RQ;
    vector<NODE> loc_flower;

    // 초록, 빨강 배양액 방문 여부 초기화
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visit_G[i][j] = -1;
            visit_R[i][j] = -1;
        }
    }
    for(int i = 0; i < G; i++) {
        //cout << "G r: " << loc_G[i].row << " c: " << loc_G[i].col << "\n";
        visit_G[loc_G[i].row][loc_G[i].col] = 0;
        GQ.push(loc_G[i]);
    }
    for(int i = 0; i < R; i++) {
        //cout << "R r: " << loc_R[i].row << " c: " << loc_R[i].col << "\n";
        visit_R[loc_R[i].row][loc_R[i].col] = 0;
        RQ.push(loc_R[i]);
    }

    while(!GQ.empty() && !RQ.empty()) {
        // 1초 증가
        sec++;

        // 초록색 배양액 확장
        int GQ_num = GQ.size();
        for(int i = 0; i < GQ_num; i++) {
            bool find = false;

            // 해당 위치가 꽃인 핀 경우
            for(int j = 0; j < loc_flower.size(); j++) {
                if(loc_flower[j].row == GQ.front().row && loc_flower[j].col == GQ.front().col) {
                    GQ.pop();
                    find = true;
                    break;
                }
            }
            if(find)
                continue;

            for(int j = 0; j < 4; j++) {
                new_r = GQ.front().row + mov[j];
                new_c = GQ.front().col + mov[3-j];
                
                // 인접 위치가 범위를 벗어난 경우
                if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M)
                    continue;
                // 해당 위치가 미방문이고 호수가 아닌 경우
                if(visit_G[new_r][new_c] < 0 && garden[new_r][new_c]) {
                    visit_G[new_r][new_c] = sec;
                    tmp.row = new_r; tmp.col = new_c;
                    GQ.push(tmp);
                }
            }
            GQ.pop();
        } 
        loc_flower.clear();

        // 빨강색 배양액 확장
        int RQ_num = RQ.size();
        for(int i = 0; i < RQ_num; i++) {
            for(int j = 0; j < 4; j++) {
                new_r = RQ.front().row + mov[j];
                new_c = RQ.front().col + mov[3-j];
                
                // 인접 위치가 범위를 벗어난 경우
                if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M)
                    continue;
                // 해당 위치가 미방문이고 호수가 아닌 경우
                if(visit_R[new_r][new_c] < 0 && garden[new_r][new_c]) {
                    visit_R[new_r][new_c] = sec;
                    tmp.row = new_r; tmp.col = new_c;
                    // 해당 위치가 초록 배양액과 동일한 시간에 뿌려지는 경우
                    if(visit_G[new_r][new_c] == sec) {
                        //cout << "flower: " << flower << " r: " << new_r << " c: " << new_c << "\n";
                        flower++;
                        loc_flower.push_back(tmp);
                    }
                    else
                        RQ.push(tmp);
                }
            }
            RQ.pop();
        } 
    }

    // 최대 꽃 개수 업데이트
    if(flower > max_flower)
        max_flower = flower;
}