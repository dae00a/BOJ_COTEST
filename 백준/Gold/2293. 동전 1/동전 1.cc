#include <bits/stdc++.h>
using namespace std;

int N, K;
int dp[10001];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> K;
    int cost;
    // 어떤 종류의 동전이든 0원을 만들 수 있는 경우의 수 = 1
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        cin >> cost;
        for(int j = 1; j <= K; j++) {
            // 최소 하나의 cost 종류의 동전을 사용하는 경우,
            // 이전의 종류의 동전으로 만들 수 있는 경우의 수 = j - cost의 경우의 수
            // 적어도 하나의 cost가 존재하고 나머지 값 만큼의 경우의 수는 dp[j - cost]에 저장되어 있기 때문.
            if(j - cost >= 0)
                dp[j] += dp[j - cost];
        }
    }

    cout << dp[K] << "\n";

    return 0;
}