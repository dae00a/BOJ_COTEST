/*
    첫 번째 배열을 정렬 후 두 번째 배열을 차례로 선택하여 이분탐색.
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
    vector<int> second_v(M);

    for(int i = 0; i < M; i++) {
        cin >> second_v[i];
        if(binary_search(first_v.begin(), first_v.end(), second_v[i])) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }

    return 0;
}