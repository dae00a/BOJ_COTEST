#include <bits/stdc++.h>
using namespace std;

int clothes[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 0; i < lost.size(); i++)
        clothes[lost[i]]--;
    for(int i = 0; i < reserve.size(); i++)
        clothes[reserve[i]]++;
    for(int i = 1; i <= n; i++) {
        if(clothes[i] < 0) {
            if(clothes[i-1] > 0) {
                clothes[i-1]--;
                clothes[i]++;
            }
            else if(clothes[i+1] > 0) {
                clothes[i+1]--;
                clothes[i]++;
            }
        }
        if(clothes[i] >= 0)
            answer++;
    }
    
    return answer;
}