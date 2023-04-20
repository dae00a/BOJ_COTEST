#include <bits/stdc++.h>
using namespace std;

typedef struct DISJOINTSET {
    int parent[101];
    
    void initialize(int n) {
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int e) {
        if(parent[e] == e)
            return e;
        return find(parent[e]);
    }
    
    void merge(int e1, int e2) {
        e1 = find(e1), e2 = find(e2);
        if(e1 == e2)
            return ;
        if(e1 < e2)
            parent[e2] = e1;
        else
            parent[e1] = e2;
    }
} DISJOINTSET;

bool cmp(vector<int> &v1, vector<int> &v2) {
    if(v1[2] == v2[2]) {
        if(v1[0] == v2[0])
            return (v1[1] < v2[1]);
        return (v1[0] < v2[0]);
    }
    return (v1[2] < v2[2]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp);
    DISJOINTSET disjointset;
    disjointset.initialize(n);
    
    for(int i = 0; i < costs.size(); i++) {
        int u = costs[i][0], v = costs[i][1], cost = costs[i][2];
        if(disjointset.find(u) == disjointset.find(v))
            continue;
        disjointset.merge(u, v);
        answer += cost;
    }
    
    return answer;
}