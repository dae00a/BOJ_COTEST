#include <bits/stdc++.h>

using namespace std;

int N;
long long A[1000001], B, C;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    cin >> B >> C;

    long long num = 0;
    for(int i = 0; i < N; i++) {
        A[i] -= B;
        num++;
        if(A[i] > 0)
            num += (A[i] / C + (A[i] % C ? 1 : 0));
    }

    cout << num << "\n";

    return 0;
}