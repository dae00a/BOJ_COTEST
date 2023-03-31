#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[101];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 1; i <= 3; i++) 
        dp[i] = i;

    for(int i = 4; i <= N; i++) {
        for(int j = 1; j <= i - 3; j++) {
            dp[i] = max(dp[i], max(dp[i-1] + 1, dp[i-(j+2)] * (j + 1)));
        }
    }

    cout << dp[N] << "\n";

    return 0;
}