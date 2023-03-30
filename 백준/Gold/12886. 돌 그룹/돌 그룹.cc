#include <bits/stdc++.h>

using namespace std;

typedef struct NODE {
    int g[3];
} NODE;

bool group[501][501][501];

bool solution(int *g);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int g[3];
    for(int i = 0; i < 3; i++)
        cin >> g[i];
    sort(g, g+3);

    if((g[0] + g[1] + g[2]) % 3)
        cout << "0\n";
    else if(solution(g))
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}

bool solution(int *g) {
    queue<NODE> q;
    q.push({g[0], g[1], g[2]});
    group[g[0]][g[1]][g[2]] = true;

    while(!q.empty()) {
        int tmp[3];
        for(int i = 0; i < 3; i++)
            tmp[i] = q.front().g[i];

        if((tmp[0] == tmp[1]) && (tmp[1] == tmp[2]))
            return true;

        for(int i = 0; i < 3; i++) {
            int a[3];
            a[i%2] = 2 * tmp[i%2];    
            a[(i+1>2?2:i+1)] = tmp[(i+1>2?2:i+1)] - tmp[i%2];
            a[(i+2)%3] = tmp[(i+2)%3];

            sort(a, a+3);

            if(group[a[0]][a[1]][a[2]])
                continue;
            
            q.push({a[0], a[1], a[2]});
            group[a[0]][a[1]][a[2]] = true;
        }

        q.pop();
    }

    return false;
}