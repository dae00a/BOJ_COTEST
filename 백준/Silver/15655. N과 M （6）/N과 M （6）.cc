#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8], new_arr[8];

void combination(int cnt, int next);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr+N);

    combination(0, 0);

    return 0;
}

void combination(int cnt, int next) {
    if(cnt == M) {
        for(int i = 0; i < M; i++)
            cout << new_arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = next; i < N; i++) {
        new_arr[cnt] = arr[i];
        combination(cnt+1, i+1);
    }
}