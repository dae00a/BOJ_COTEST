#include <bits/stdc++.h>
using namespace std;

int N;
int dp[2];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    dp[0] = 1; dp[1] = 2;
    
    cin >> N;
    
    int tmp;
    if(N == 1)
        tmp = 1;
    else if(N == 2)
        tmp = 2;

    for(int i = 2; i < N; i++) {
        tmp = dp[1] + dp[0];
        tmp = tmp % 15746;
        dp[0] = dp[1]; 
        dp[1] = tmp;
    }

    cout << tmp << "\n";

    return 0;
}