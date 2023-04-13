#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int stown, etown, boxes;
} NODE;

int N, C, M;
vector<NODE> v;

bool comp(NODE a, NODE b);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> C >> M;
    for(int i = 0; i < M; i++) {
        int s, e, b;
        cin >> s >> e >> b;
        v.push_back({s, e, b});
    }

    sort(v.begin(), v.end(), comp);

    int cur_c = 0, n = 0, accum_c = 0;
    vector<int> bv(N + 1, 0);
    for(int loc = N; loc > 0; loc--) {
        // 현재 마을에 저장했던 박스 드랍.
        cur_c -= bv[loc];
        accum_c += bv[loc];

        while(v[n].etown >= loc) {
            // 트럭 용량이 남아있는 경우
            if(cur_c < C) {
                int possible_c = min(C - cur_c, v[n].boxes);
                bv[v[n].stown] += possible_c;
                cur_c += possible_c; 
            } 

            n++;
        }
    }

    cout << accum_c << "\n";

    return 0;
}

bool comp(NODE a, NODE b) {
    if(a.etown < b.etown) {
        return false;
    }
    if(a.stown < b.stown) {
        return false;
    }
    return true;
}