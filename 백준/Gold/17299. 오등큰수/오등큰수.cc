#include <bits/stdc++.h>

#define MAX_LEN (int)1e6

using namespace std;

int N;
int A[MAX_LEN+1], F[MAX_LEN+1], ans[MAX_LEN+1];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A[i] = tmp;
        F[tmp]++;
    }

    stack<pair<int, int>> st;
    for(int i = N - 1; i >= 0; i--) {
        while(!st.empty() && F[A[i]] >= st.top().second)
            st.pop();
        if(st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top().first;

        st.push({A[i], F[A[i]]});
    }
    
    for(int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}