#include <bits/stdc++.h>
using namespace std;

int N;
// [0]: R, [1]: G, [2]: B
int house[1000][3];
int dp[1000][3];
int min_cnt;

void recursion(int cnt, int color);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> house[i][j];
            if(i == N - 1) 
                dp[i][j] = house[i][j];
        }
    }

    recursion(0, 0);
    recursion(0, 1);
    recursion(0, 2);

    min_cnt = min(dp[0][0], min(dp[0][1], dp[0][2]));
    cout << min_cnt << "\n";

    return 0;
}

void recursion(int cnt, int color) {
    // dp에 최소값을 갖는 값이 존재 하는 경우
    if(dp[cnt + 1][(color + 1) % 3] && dp[cnt + 1][(color + 2) % 3]) {
        dp[cnt][color] = house[cnt][color] + min(dp[cnt + 1][(color + 1) % 3], dp[cnt + 1][(color + 2) % 3]);
        return ;
    }   
    else {
        recursion(cnt + 1, (color + 1) % 3);
        recursion(cnt + 1, (color + 2) % 3);
        dp[cnt][color] = house[cnt][color] + min(dp[cnt + 1][(color + 1) % 3], dp[cnt + 1][(color + 2) % 3]);
    }
}