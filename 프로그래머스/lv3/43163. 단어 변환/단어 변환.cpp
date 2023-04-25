#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, K;
int visited[51];

int solution(string begin, string target, vector<string> words) {
    int answer = INF;
    N = words.size();
    K = begin.length();
    
    memset(visited, 50, 51 * sizeof(int));
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    while(!q.empty()) {
        string cur_str = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur_str == target) {
            answer = min(answer, cnt);
            continue;
        }
        
        for(int i = 0; i < N; i++) {
            if(cur_str == words[i])
                continue;
            if(cnt + 1 >= visited[i])
                continue;
            
            int diff = 0;
            for(int j = 0; j < K; j++) {
                if(cur_str[j] != words[i][j])
                    diff++;
            }
            if(diff != 1)
                continue;
            
            visited[i] = cnt + 1;
            q.push({words[i], cnt + 1});
        }
    }
    
    if(answer >= INF)
        answer = 0;
    
    return answer;
}