#include <bits/stdc++.h>

#define MAX_COST 987654321

using namespace std;

int T, K;
int dp[501][501], sum[501];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> T;
    while(T--) {
        cin >> K;
        for(int i = 1; i <= K; i++) {
            int c;
            cin >> c;
            sum[i] = sum[i-1] + c;
        }

        for(int i = 1; i < K; i++) {
            for(int s = 1; s + i <= K; s++) {
                int e = s + i;
                
                dp[s][e] = MAX_COST;
                for(int k = s; k < e; k++)
                    dp[s][e] = min(dp[s][e], dp[s][k] + dp[k+1][e] + sum[e] - sum[s-1]);
            }
        } 

        cout << dp[1][K] << "\n";
    }

    return 0;
}