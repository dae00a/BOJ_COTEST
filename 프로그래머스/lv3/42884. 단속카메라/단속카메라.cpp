#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &v1, vector<int> &v2) {
    if(v1[1] == v2[1])
        return (v1[0] < v2[0]);
    return (v1[1] < v2[1]);
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), comp);
    
    int loc = routes[0][1];
    for(int i = 0; i < routes.size(); i++) {
        if(loc < routes[i][0]) {
            loc = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}