#include <bits/stdc++.h>
using namespace std;

int N, T;
int node[100001][3];
int dp[100001][3];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    while(1) {
        cin >> N;

        if(!N)
            return 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < 3; j++) 
                cin >> node[i][j];

            if(i == 0) {
                dp[i][1] = node[i][1];
                dp[i][2] = node[i][2] + node[i][1];
            }
            else if(i == 1) {
                int m = min(dp[i-1][1], dp[i-1][2]);

                dp[i][0] = node[i][0] + node[i-1][1];
                dp[i][1] = node[i][1] + min(m, dp[i][0]);
                dp[i][2] = node[i][2] + min(m, dp[i][1]);    
            }
            else {
                int m1 = min(dp[i-1][0], dp[i-1][1]);
                int m2 = min(dp[i-1][1], dp[i-1][2]);

                dp[i][0] = node[i][0] + m1;
                dp[i][1] = node[i][1] + min(min(m1, dp[i-1][2]), dp[i][0]);
                dp[i][2] = node[i][2] + min(m2, dp[i][1]);
            }
        }  

        cout << ++T << ". ";
        cout << dp[N-1][1] << "\n";
    }

    return 0;
}