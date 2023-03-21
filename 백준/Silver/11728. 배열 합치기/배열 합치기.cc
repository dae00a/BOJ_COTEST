#include <bits/stdc++.h>

#define MAX_SIZE 1e6

using namespace std;

int N, M;
vector<int> A(2 * MAX_SIZE), B(2 * MAX_SIZE);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < M; i++)
        cin >> B[i];

    /* 두 배열을 합친 다음 sort
    for(int i = 0; i < M; i++)
        A[N+i] = B[i];
        
    sort(A.begin(), A.begin() + (N + M));

    for(int i = 0; i < (N + M); i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    */

    // 두 배열을 sort한 후 합치기    
    vector<int> C;

    sort(A.begin(), A.begin() + N);
    sort(B.begin(), B.begin() + M);

    int a = 0, b = 0;
    while(a <= N && b <= M) {
        if((a < N && A[a] <= B[b]) || (b >= M)) {
            C.push_back(A[a++]);
        }    
        else {
            C.push_back(B[b++]);
        }
    }
    
    for(int i = 0; i < (N + M); i++) {
        cout << C[i] << " ";
    }
    cout << "\n";
    //

    return 0;
}