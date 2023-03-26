#include <bits/stdc++.h>

using namespace std;

int N;
int dist[3001], cycStrt;
list<int> adjList[3001];
bool visiting[3001];

void dfs(int now, int from);
void bfs();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    memset(dist, -1, 3001 * sizeof(int));

    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1, 1);
    bfs();

    for(int i = 1; i <= N; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}

void dfs(int now, int from) {
    for(auto it = adjList[now].begin(); it != adjList[now].end(); it++) {
        if(*it == from)
            continue;
        if(visiting[*it]) {
            cycStrt = *it;
            dist[now] = 0;
            return ;
        }
        else {
            visiting[now] = true;
            dfs(*it, now);
            if(cycStrt > 0) {
                dist[now] = 0;
                visiting[now] = false;
                if(now == cycStrt)
                    cycStrt = 0;
                return ;
            }
            visiting[now] = false;
        }
    }
}

void bfs() {
    for(int i = 1; i <= N; i++) {
        queue<pair<int, int>> q;
        bool flag = false;

        if(!dist[i])
            continue;

        memset(visiting, 0, 3001 * sizeof(bool));
        q.push({i, 1});
        visiting[i] = true;

        while(!q.empty()) {
            for(auto it = adjList[q.front().first].begin(); it != adjList[q.front().first].end(); it++) {
                if(visiting[*it])
                    continue;
                
                if(!dist[*it]) {
                    dist[i] = q.front().second;
                    flag = true;
                }
                else {
                    q.push({*it, q.front().second + 1});
                    visiting[*it] = true;
                }
            }
            if(flag)
                break;

            q.pop();
        }
    }
}