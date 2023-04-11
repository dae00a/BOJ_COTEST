#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[7], new_arr[7];

void permutation(int cnt);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++) 
        cin >> arr[i];
    sort(arr, arr + N);

    permutation(0);

    return 0;
}

void permutation(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++)
            cout << new_arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++) {
        new_arr[cnt] = arr[i];
        permutation(cnt+1);
    }
}