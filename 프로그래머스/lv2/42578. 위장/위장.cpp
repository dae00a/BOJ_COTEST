#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0, size = clothes.size();
    unordered_map<string, int> cmap;
    vector<int> v(31, 0);
    
    int id = 0;
    for(int i = 0; i < size; i++) {
        if(cmap.find(clothes[i][1]) == cmap.end()) {
            cmap[clothes[i][1]] = id;
            id++;
        }
        
        v[cmap[clothes[i][1]]]++;
    }
    
    int res = 1;
    for(int i = 0; i < id; i++)
        res *= (v[i] + 1);    
    
    answer = res - 1;
    return answer;
}