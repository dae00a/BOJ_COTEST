#include <bits/stdc++.h>
using namespace std;

typedef struct pair<int, pair<int, int>> P;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, P> smap;
    int size = genres.size();
    
    // 장르별 총 재생횟수, 재생 횟수가 최대인 고유번호 top2
    for(int i = 0; i < size; i++) {
        if(smap.find(genres[i]) == smap.end())
            smap[genres[i]].second = {-1, -1};
        
        smap[genres[i]].first += plays[i];
        int top1 = smap[genres[i]].second.first, top2 = smap[genres[i]].second.second;
        if(top1 < 0 || plays[top1] < plays[i]) {
            smap[genres[i]].second.first = i;
            smap[genres[i]].second.second = top1;
        }
        else if(top2 < 0 || plays[top2] < plays[i]) {
            smap[genres[i]].second.second = i;
        }
    }

    // 장르 재생 횟수 내림차순 정렬
    vector<P> v;
    for(auto it = smap.begin(); it != smap.end(); it++)
        v.push_back((*it).second);
    sort(v.begin(), v.end(), greater<P>());
    int vsize = v.size();
    
    for(int i = 0; i < vsize; i++) {
        int top1 = v[i].second.first, top2 = v[i].second.second;
        if(top1 >= 0)
            answer.push_back(top1);
        if(top2 >= 0)
            answer.push_back(top2);
    }
    
    return answer;
}