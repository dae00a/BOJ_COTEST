#include <bits/stdc++.h>
using namespace std;

int N;
int dp[10][1000];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
 
    int sum;
    for(int i = 0; i < N; i++) {
        sum = 1;
        dp[9][i] = 1;
        for(int j = 8; j >= 0; j--) {
            if(i == 0)
                dp[j][i] = 1;
            dp[j][i] = dp[j][i-1] + dp[j+1][i];
            dp[j][i] %= 10007;
            sum += dp[j][i];
            sum %= 10007;
        }
    }
    
    cout << sum << "\n";
    
    return 0;
}