#include <bits/stdc++.h>

using namespace std;

int N, M, T;
int dn[] = {0, 1, 0, -1}, dm[] = {1, 0, -1, 0};

vector<deque<int>> disk(51);

void rotate(int n, int direct, int k);
void bfs();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M >> T;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < M; j++) {
            int num;
            cin >> num;
            disk[i].push_back(num);
        }
    }

    while(T--) {
        int x, d, k;
        cin >> x >> d >> k;

        for(int i = 1; i * x <= N; i++) 
            rotate(i * x, d, k);
        
        bfs();
    }

    int answer = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < M; j++)
            answer += disk[i][j];
    }

    cout << answer << "\n";

    return 0;
}

void rotate(int n, int direct, int k) {
    int tmp;
    while(k--) {
        if(direct) {
            tmp = disk[n].front();
            disk[n].pop_front();
            disk[n].push_back(tmp);
        }
        else {
            tmp = disk[n].back();
            disk[n].pop_back();
            disk[n].push_front(tmp);
        }
    }
}

void bfs() {
    bool adj = false;
    bool same_val[N+1][M];
    int sum = 0, cnt = 0; 

    for(int i = 0; i <= N; i++)
        memset(same_val[i], false, M);

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < M; j++) {
            if(disk[i][j] <= 0 || same_val[i][j])
                continue;

            sum += disk[i][j];
            cnt++;

            for(int k = 0; k < 4; k++) {
                int new_n = i + dn[k], new_m = (j + dm[k] + M) % M;

                if(new_n <= 0 || new_n > N)
                    continue;
                
                if(disk[i][j] == disk[new_n][new_m]) {
                    same_val[i][j] = true;
                    same_val[new_n][new_m] = true;
                    adj = true;
                }
            }
        }
    }

    if(adj) {
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < M; j++) {
                if(same_val[i][j])
                    disk[i][j] = 0;
            }
        }
    }
    else {
        double avg = (double)sum / cnt;

        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < M; j++) {
                if(disk[i][j] <= 0)
                    continue;
                if(disk[i][j] < avg)
                    disk[i][j]++;
                else if(disk[i][j] > avg)
                    disk[i][j]--;
            }
        }
    }
}