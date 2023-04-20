#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = (long long)(1e18);
    int num = times.size();
    
    long long lp = 1, rp = answer;
    while(lp <= rp) {
        long long mid = (lp + rp) / 2, N = 0;
        for(int i = 0; i < num; i++)
            N += mid / (long long)times[i];
    
        if(n <= N) {
            answer = min(answer, mid);
            rp = mid - 1;
        }
        else
            lp = mid + 1;
    }
    
    return answer;
}