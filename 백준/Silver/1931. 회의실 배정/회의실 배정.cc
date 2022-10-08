/*
 * 가장 빨리 끝나는 회의 선택하여 최적해를 구하는 문제.
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
// [i]번째 회의의 [2]([0]: 시작 시간,[1]: 종료 시간)
vector<pair<int, int>> conf;

bool cmp(pair<int, int> a, pair<int, int> b);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    
    int st, end;
    for(int i = 0; i < N; i++) {
        cin >> st >> end;
        conf.push_back({st, end});
    }

    // 종료 시간 기준 오름차순 정렬
    sort(conf.begin() , conf.end(), cmp);

    int fin = -1;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        /*
        * 다음 회의의 시작 시간이 이전 회의의 종료시간 보다 크거나 같은 경우
        * 해당 회의를 선택하면 다른 회의를 선택하는 것보다 빨리 끝나는 선택이 됨
        */ 
        if(fin <= conf[i].first) {
            fin = conf[i].second;
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second < b.second)
        return true;
    if(a.second == b.second && a.first < b.first)
        return true;
    else
        return false;
}