#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N, M;
vector<int> seq(2001);
vector<vector<bool>> dp(2001, vector<bool> (2001, 0));

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> seq[i];
        dp[i][i] = true;
        if(seq[i-1] == seq[i]) {
            dp[i-1][i] = true;
        }
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            // 칠판에 적은 수의 최댓값이 2000 이하이여야 한다.
            // 각각 범위의 끝값이 같고 사이의 값들이 pelindrome인 경우 해당 범위도 pelindrome이다.
            if(i + j <= 2000 && seq[j] == seq[i+j] && dp[j+1][i+j-1]) {
                dp[j][i+j] = true;
            }
        }
    }

    cin >> M;
    int S, E;
    for(int i = 0; i < M; i++) {
        cin >> S >> E;
        cout << dp[S][E] << "\n"; 
    }

    return 0;
}