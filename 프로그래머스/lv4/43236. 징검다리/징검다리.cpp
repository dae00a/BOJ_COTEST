#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    int lp = 1, rp = distance;
    while(lp <= rp) {
        int k = (lp + rp) / 2, prev_rock = 0, removed = 0, min_dist = distance;
        
        for(int i = 0; i < rocks.size(); i++) {
            int dist = rocks[i] - prev_rock;
            if(dist < k)
                removed++;
            else {
                prev_rock = rocks[i];
                min_dist = min(min_dist, dist);
            }
        }
            
        if(n < removed)
            rp = k - 1;
        else {
            answer = min_dist;
            lp = k + 1;   
        }
    }
    
    return answer;
}