// 재귀적으로 분할정복을 수행하는 병합정렬
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N, K;
vector<int> tmp(500000);

void merge_sort(vector<int> &a, int p, int r);
void merge(vector<int> &a, int p, int q, int r);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    merge_sort(A, 0, A.size() - 1);

    if(K > 0) {
        cout << -1 << "\n";
    }

    return 0;
}

void merge_sort(vector<int> &a, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        merge_sort(a, p, q); 
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void merge(vector<int> &a, int p, int q, int r) {
    int i = p, j = q + 1, t = 0;

    // 중간값 이전 배열과 이후 배열 중 작은 값을 임시 배열에 저장.
    // vector<int> tmp(N); container 반복적으로 생성 시 시간초과.
    while(i <= q && j <= r) {
        if(a[i] <= a[j]) {
            tmp[t++] = a[i++];
        }
        else {
            tmp[t++] = a[j++];
        }
    }
    while(i <= q) {
        tmp[t++] = a[i++];
    }
    while(j <= r) {
        tmp[t++] = a[j++];
    }

    // 임시 배열에 저장된 값을 p위치부터 차례로 A 배열에 저장.
    i = p; t = 0;
    while(i <= r) {
        if(--K == 0) {
            cout << tmp[t] << "\n";
            exit(0);
        }

        a[i++] = tmp[t++];
    }
}