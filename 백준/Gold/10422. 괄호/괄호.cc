#include <bits/stdc++.h>

#define MAX_L (5000 / 2)
#define MOD (long long)(1e9 + 7)

using namespace std;

long long A[MAX_L+1][MAX_L+1];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    A[1][1] = 1;
    for(int i = 1; i < MAX_L + 1; i++) {
        A[i][i] = 1;
        A[i][0] += i * A[i][i];

        for(int j = i - 1; j > 1; j--) {
            A[i][j] = (A[i][j+1] + A[i-1][j-1]) % MOD;
            A[i][0] += j * A[i][j];
            A[i][0] %= MOD;
        }
    }

    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int L, ans = 0;
        cin >> L;

        if(!(L % 2))
            ans = A[L/2][0];
            
        cout << ans << "\n";
    }

    return 0;
}