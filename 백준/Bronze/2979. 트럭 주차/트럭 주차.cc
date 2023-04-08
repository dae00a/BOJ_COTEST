#include <bits/stdc++.h>

using namespace std;

int cost[4];
int car[101];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    for(int i = 1; i <= 3; i++)
        cin >> cost[i];
    for(int i = 0; i < 3; i++) {
        int s, e;
        cin >> s >> e;
        for(int i = s; i < e; i++) 
            car[i]++;
    }

    int ans = 0;
    for(int i = 1; i <= 100; i++)
        ans += (cost[car[i]] * car[i]);

    cout << ans << "\n";

    return 0;
}