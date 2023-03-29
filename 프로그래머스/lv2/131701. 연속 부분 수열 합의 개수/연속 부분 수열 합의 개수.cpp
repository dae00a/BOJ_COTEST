#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int N = elements.size();
    set<int> vSet;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < N; j++) {
            int sum = 0;
            for(int k = j; k < j + i; k++)
                sum += elements[k % N];
            vSet.insert(sum);
        }
    }
    answer = vSet.size();
    
    return answer;
}