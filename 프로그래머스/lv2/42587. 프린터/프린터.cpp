#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, psize = priorities.size();
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < psize; i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
        
    while(!q.empty()) {
        if(q.front().second >= pq.top()) {
            answer++;
            if(q.front().first == location)
                break;
            pq.pop();
        }
        else
            q.push(q.front());
        q.pop();
    }
    
    return answer;
}