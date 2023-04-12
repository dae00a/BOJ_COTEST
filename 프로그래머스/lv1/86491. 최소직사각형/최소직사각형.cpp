#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int size = sizes.size(), max_w = 0, max_h = 0;
    for(int i = 0; i < size; i++) {
        max_w = max(max_w, max(sizes[i][0], sizes[i][1]));
        max_h = max(max_h, min(sizes[i][0], sizes[i][1]));
    }
    
    answer = max_w * max_h;
    
    return answer;
}