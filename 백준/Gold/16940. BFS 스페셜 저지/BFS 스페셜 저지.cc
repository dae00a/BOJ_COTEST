#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G(100001);
vector<int> A;

void bfs();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    
        sort(G[i+1].begin(), G[i+1].end());
    }

    if(A[0] != 1) {
        cout << "0\n";
    }
    else {
        bfs();
    }

    return 0;
}

void bfs() {
    int t = 1;
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int n = q.front();
        
        while(t < N) {
            bool find = false;

            if(binary_search(G[n].begin(), G[n].end(), A[t])) {
                q.push(A[t]);
                find = true;
            }

            if(find)
                t++;
            else 
                break;
        }
        
        q.pop();
    }

    if(t < N)
        cout << "0\n";
    else 
        cout << "1\n";
}