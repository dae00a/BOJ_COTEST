#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++) {
        int s = commands[i][0], e = commands[i][1], k = commands[i][2];
        vector<int> tmp(array.begin() + (s - 1), array.begin() + e);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k-1]);
    }
    
    return answer;
}