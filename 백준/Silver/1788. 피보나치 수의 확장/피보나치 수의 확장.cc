#include <bits/stdc++.h>
using namespace std;

#define LIM 1000001

int N;
long long plus_dp[LIM];
long long minus_dp[LIM];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    plus_dp[0] = 0; plus_dp[1] = 1;
    minus_dp[0] = 0; minus_dp[1] = 1;
    for(int i = 2; i < LIM; i++) {
        plus_dp[i] = plus_dp[i - 1] + plus_dp[i - 2];
        plus_dp[i] %= 1000000000;
        minus_dp[i] = minus_dp[i - 2] - minus_dp[i - 1];
        minus_dp[i] %= 1000000000;
    }

    cin >> N;

    if(!N) 
        cout << 0 << "\n" << 0 << "\n";
    else if(N < 0) {
        N = abs(N);
        if(minus_dp[N] < 0)
            cout << -1 << "\n";
        else if(minus_dp[N] > 0)
            cout << 1 << "\n";
        cout << abs(minus_dp[N]) << "\n";
    }
    else 
        cout << 1 << "\n" << plus_dp[N] << "\n";

    return 0;
}