#include <bits/stdc++.h>
using namespace std;

typedef struct NODE {
    int num, direct;
} NODE;

typedef struct FISH {
    int y, x;
    bool live;
} FISH;

int answer;
vector<vector<NODE>> mat(4, vector<NODE>(4));
vector<FISH> fish(17);
const int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1}, dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void dfs(int sum, int shrk_y, int shrk_x, vector<vector<NODE>> node, vector<FISH> flist);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> mat[i][j].num >> mat[i][j].direct;
            fish[mat[i][j].num] = {i, j, true};
        }
    }
    
    dfs(0, 0, 0, mat, fish);

    cout << answer << "\n";

    return 0;
}

void dfs(int sum, int shrk_y, int shrk_x, vector<vector<NODE>> node, vector<FISH> flist) {
    // 상어 위치 및 최대값 갱신
    sum += node[shrk_y][shrk_x].num;
    flist[node[shrk_y][shrk_x].num].live = false;
    node[shrk_y][shrk_x].num = 0;

    answer = max(answer, sum);

    // 물고기 이동
    for(int i = 1; i <= 16; i++) {
        if(!flist[i].live)
            continue;
        
        int d = node[flist[i].y][flist[i].x].direct;
        int nfish_y, nfish_x;
        for(int j = 0; j < 8;) {
            nfish_y = flist[i].y + dy[d], nfish_x = flist[i].x + dx[d];

            if(nfish_y < 0 || nfish_y >= 4 || nfish_x < 0 || nfish_x >= 4
                || (nfish_y == shrk_y && nfish_x == shrk_x)) {
                d = (d + 1) % 9;
                if(d <= 0)
                    d = 1;

                continue;
            }
            
            break;
        }
        
        // 물고기 swap
        NODE tmp = node[flist[i].y][flist[i].x];
        node[flist[i].y][flist[i].x] = node[nfish_y][nfish_x];
        node[nfish_y][nfish_x] = tmp;
        node[nfish_y][nfish_x].direct = d;

        // 물고기 리스트 갱신
        if(node[nfish_y][nfish_x].num > 0) {
            flist[node[flist[i].y][flist[i].x].num].y = flist[i].y;
            flist[node[flist[i].y][flist[i].x].num].x = flist[i].x;
        }
        flist[i].y = nfish_y;
        flist[i].x = nfish_x;
    }

    // 상어 이동
    int shrk_direct = node[shrk_y][shrk_x].direct;

    for(int i = 1; i <= 3; i++) {
        int nshrk_y = shrk_y + i * dy[shrk_direct], nshrk_x = shrk_x + i *  dx[shrk_direct];

        if(nshrk_y < 0 || nshrk_y >= 4 || nshrk_x < 0 || nshrk_x >= 4)
            continue;
        if(node[nshrk_y][nshrk_x].num <= 0)
            continue;

        // 상어가 (nshrk_y, nshrk_x)로 이동 가능
        dfs(sum, nshrk_y, nshrk_x, node, flist);
    }
}