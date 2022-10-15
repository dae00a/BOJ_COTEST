/*
    1920번 문제와 동일. 단, 반복 기준은 첫 번째 배열에 값이 존재하는 지 여부.
*/
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    vector<int> first_v(N);
    for(int i = 0; i < N; i++) {
        cin >> first_v[i];
    }

    sort(first_v.begin(), first_v.end());

    cin >> M;
    int second_v;
    for(int i = 0; i < M; i++) {
        cin >> second_v;
        int lower = lower_bound(first_v.begin(), first_v.end()
                                , second_v) - first_v.begin();
        int upper = upper_bound(first_v.begin(), first_v.end()
                                , second_v) - first_v.begin();
        int cnt = upper - lower;
        cout << cnt << " ";
    }
    cout << "\n";

    return 0;
}