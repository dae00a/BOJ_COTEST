#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for(int h = 0; h <= 10000; h++) {
        int loc = lower_bound(citations.begin(), citations.end(), h) - citations.begin();
        int hlower = citations.size() - loc;
        loc = upper_bound(citations.begin(), citations.end(), h) - citations.begin();
        int hupper = loc;
        
        if(h <= hlower && hupper <= h)
            answer = max(answer, h);
    }
        
    return answer;
}