#include <bits/stdc++.h>

using namespace std;

int N;
list<int> tree[100001];
set<int> S[100001];
int A[100001], t;
bool check[100001];

void dfs(int x);
void solution(int x);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i = 0; i < N; i++)
        cin >> A[i];

    dfs(1);
    solution(1);

    cout << "1\n";

    return 0;
}

void dfs(int x) {
    if(check[x])
        return ;
    check[x] = true;
    for(auto it = tree[x].begin(); it != tree[x].end(); it++) {
        if(check[*it])
            continue;
        S[x].insert(*it);
        dfs(*it);
    }   
}

void solution(int x) {
    while(!S[x].empty()) {
        if(S[x].find(A[t+1]) != S[x].end()) {
            S[x].erase(A[t+1]);
            t++;
            solution(A[t]);
        }
        else {
            cout << "0\n";
            exit(0);
        }
    }
}