#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = scoville.size();
    
    for(int i = 0; i < size; i++)
        pq.push(scoville[i]);
    
    while(pq.size() > 1 && pq.top() < K) {
        int least_scov = pq.top();
        pq.pop();
        int less_scov = pq.top();
        pq.pop();
        
        int new_scov = least_scov + less_scov * 2;
        pq.push(new_scov);
        answer++;
    }
    
    if(pq.top() < K)
        answer = -1;
    
    return answer;
}