#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> mat(11, vector<int>(101, 0));
const int dy[] = {1, 0}, dx[] = {0, 1};

int solution();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> mat[10][i];

    int answer = 0;
    answer = solution();

    cout << answer << "\n";

    return 0;
}

int solution() {
    int cnt = 0;

    while(1) {
        int max_val = 0, min_val = 10001;

        for(int i = 0; i < N; i++) {
            max_val = max(max_val, mat[10][i]);
            min_val = min(min_val, mat[10][i]);
        }

        if(max_val - min_val <= K)
            break;
        
        // 어항 정리 1
        for(int i = 0; i < N; i++) {
            if(mat[10][i] == min_val)
                mat[10][i]++;
        }

        // 어항 정리 2
        int s = 0, t = 1;
        bool flag = false;
        while(s / t + 1 <= N - s - t) {
            int col = s;
            for(int i = t; i > 0; i--) {
                for(int j = 0; mat[10-j][col] > 0; j++) {
                    mat[10-i][s+t+j] = mat[10-j][col];
                    mat[10-j][col] = 0;
                }
                col++;
            }
            s += t;

            if(flag) {
                flag = false;
                t++;
            }
            else
                flag = true;
        }

        // 어항 정리 3
        vector<vector<int>> mv(11, vector<int>(101, 0));
        
        for(int y = 0; y <= 10; y++) {
            for(int x = 0; x < N; x++) {
                if(!mat[y][x])
                    continue;

                for(int i = 0; i < 2; i++) {
                    int new_y = y + dy[i], new_x = x + dx[i];

                    if(new_y < 0 || new_y > 10 || new_x < 0 || new_x > 100)
                        continue;
                    if(!mat[new_y][new_x])
                        continue;

                    int diff = abs(mat[new_y][new_x] - mat[y][x]);
                    int d = diff / 5;
                    
                    if(d <= 0)
                        continue;

                    int large_y, large_x, small_y, small_x;

                    if(mat[new_y][new_x] > mat[y][x]) {
                        large_y = new_y; large_x = new_x; small_y = y; small_x = x;
                    }
                    else {
                        large_y = y; large_x = x; small_y = new_y; small_x = new_x;
                    }
                    mv[large_y][large_x] -= d;
                    mv[small_y][small_x] += d;
                }
            }
        }

        for(int i = 0; i <= 10; i++) {
            for(int j = 0; j < N; j++) {
                if(!mv[i][j])
                    continue;
                mat[i][j] += mv[i][j];
            }
        }

        // 어항 정리 4
        int n = 0;
        for(int i = s; n < N; i++) {
            for(int j = 0; mat[10-j][i] > 0; j++) {
                mat[10][n] = mat[10-j][i];
                if(j > 0 && n <= i)
                    mat[10-j][i] = 0;
                n++;
            }
        }

        // 어항 정리 5
        for(int i = 0; i < N / 2; i++) {
            int top_col = N / 2 - i - 1;
            int bottom_col = N / 2 + i;
            
            mat[9][bottom_col] = mat[10][top_col];
            mat[10][top_col] = 0;
        }

        for(int i = 0; i < N / 4; i++) {
            int top_col = N - N / 4 - i - 1;
            int bottom_col = N - N / 4 + i;
            
            mat[8][bottom_col] = mat[9][top_col];
            mat[7][bottom_col] = mat[10][top_col];
            mat[9][top_col] = 0;
            mat[10][top_col] = 0;
        }

        // 어항 정리 6
        vector<vector<int>> mv2(11, vector<int>(101, 0));
        
        for(int y = 0; y <= 10; y++) {
            for(int x = 0; x < N; x++) {
                if(!mat[y][x])
                    continue;

                for(int i = 0; i < 2; i++) {
                    int new_y = y + dy[i], new_x = x + dx[i];

                    if(new_y < 0 || new_y > 10 || new_x < 0 || new_x > 100)
                        continue;
                    if(!mat[new_y][new_x])
                        continue;

                    int diff = abs(mat[new_y][new_x] - mat[y][x]);
                    int d = diff / 5;
                    
                    if(d <= 0)
                        continue;

                    int large_y, large_x, small_y, small_x;

                    if(mat[new_y][new_x] > mat[y][x]) {
                        large_y = new_y; large_x = new_x; small_y = y; small_x = x;
                    }
                    else {
                        large_y = y; large_x = x; small_y = new_y; small_x = new_x;
                    }
                    mv2[large_y][large_x] -= d;
                    mv2[small_y][small_x] += d;
                }
            }
        }

        for(int i = 0; i <= 10; i++) {
            for(int j = 0; j < N; j++) {
                if(!mv2[i][j])
                    continue;
                mat[i][j] += mv2[i][j];
            }
        }

        // 어항 정리 7
        n = 0;
        for(int i = N - N / 4; n < N; i++) {
            for(int j = 0; mat[10-j][i] > 0; j++) {
                mat[10][n] = mat[10-j][i];
                if(j > 0 && n <= i)
                    mat[10-j][i] = 0;
                n++;
            }
        }

        cnt++;
    }

    return cnt;
}