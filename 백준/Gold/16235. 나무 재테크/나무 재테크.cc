#include <bits/stdc++.h>
#define P pair<int, pair<int, int>>
#define InitNourish 5
using namespace std;

int N, M, K;
const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<pair<int, vector<int>>>> land(11, vector<pair<int, vector<int>>> (11));
vector<vector<int>> A(11, vector<int> (11));

void beSpring();
void beAutumn();
void beWinter();
int getTreesCnt();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> A[i][j];
            land[i][j].first = InitNourish;
        }
    }
    for(int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        land[x][y].second.push_back(z);
    }

    for(int i = 0; i < K; i++) {
        beSpring();
        beAutumn();
        beWinter();
    }
    
    int ans = getTreesCnt();
    cout << ans << "\n";

    return 0;
}

void beSpring() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            sort(land[i][j].second.begin(), land[i][j].second.end());
            
            int treeCnt = land[i][j].second.size();
            int leftNourish = land[i][j].first;
            int sumNourish = 0;

            for(int cnt = 0; cnt < treeCnt; cnt++) {
                if(leftNourish < land[i][j].second[cnt]) {
                    while(cnt < treeCnt) {
                        sumNourish += land[i][j].second.back() / 2;
                        land[i][j].second.pop_back();
                        cnt++;
                    }
                }
                else {
                    leftNourish -= land[i][j].second[cnt];
                    land[i][j].second[cnt]++;
                }
            }

            land[i][j].first = leftNourish + sumNourish;
        } 
    }
}

void beAutumn() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int treeCnt = land[i][j].second.size();

            for(int cnt = 0; cnt < treeCnt; cnt++) {
                if(land[i][j].second[cnt] % 5)
                    continue;
                
                for(int d = 0; d < 8; d++) {
                    int newR = i + dr[d], newC = j + dc[d];

                    if(newR <= 0 || newR > N || newC <= 0 || newC > N)
                        continue;
                    land[newR][newC].second.push_back(1);
                }
            }
        }
    }
}

void beWinter() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            land[i][j].first += A[i][j];
    }
}

int getTreesCnt() {
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            cnt += land[i][j].second.size();
    }

    return cnt;
}