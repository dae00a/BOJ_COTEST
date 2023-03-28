#include <bits/stdc++.h>

using namespace std;

int N, S;
long long ans;
vector<long long> v(41);
map<long long, long long> m;

void leftSum(int cnt, long long sum);
void rightSum(int cnt, long long sum);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> v[i];

    leftSum(0, 0);
    rightSum(N / 2, 0);

    cout << (S != 0? ans : ans - 1) << "\n";

    return 0;
}

void leftSum(int cnt, long long sum) {
    if(cnt == N / 2) {
        m[sum]++;
        return ;
    }

    leftSum(cnt + 1, sum);
    leftSum(cnt + 1, sum + v[cnt]);
}

void rightSum(int cnt, long long sum) {
    if(cnt == N) {
        ans += m[S-sum];
        return ;
    }

    rightSum(cnt + 1, sum);
    rightSum(cnt + 1, sum + v[cnt]);
}