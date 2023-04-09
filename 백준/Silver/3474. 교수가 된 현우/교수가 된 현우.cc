#include <bits/stdc++.h>

using namespace std;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        long long N;
        cin >> N;

        long long cnt = 0;
        for(long long i = 5; i <= N; i *= 5)
            cnt += N / i;

        cout << cnt << "\n";
    }

    return 0;
}