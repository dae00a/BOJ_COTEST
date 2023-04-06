#include <bits/stdc++.h>

using namespace std;

int N, M;
int dp[101][10001];
vector<pair<int, int>> v(101);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> v[i].first;
    }

    int totalCost = 0;
    for(int i = 0; i < N; i++) {
        cin >> v[i].second;
        totalCost += v[i].second;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= totalCost; j++) {
            if(v[i-1].second <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1].second] + v[i-1].first);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = 0; i <= totalCost; i++) {
        if(M <= dp[N][i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}