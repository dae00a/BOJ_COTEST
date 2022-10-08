/*
 * 가장 빨리 끝나는 회의 선택하여 최적해를 구하는 문제.
 */
/*
 * 기본적으로 sort 시에 오름차순 정렬을 수행.
 * 오름차순 정렬 시 pair의 first를 기준으로 우선 정렬
*/
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    // [i]번째 회의의 [2]([1]: 시작 시간,[0]: 종료 시간)
    // * 미리 벡터의 크기를 지정해주지 않으면 index로 벡터에 접근 불가.
    vector<pair<int, int>> conf(N);

    for(int i = 0; i < N; i++) {
        cin >> conf[i].second >> conf[i].first;
    }

    // 종료 시간 기준 오름차순 정렬
    sort(conf.begin() , conf.end());

    int fin = -1;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        /*
        * 다음 회의의 시작 시간이 이전 회의의 종료시간 보다 크거나 같은 경우
        * 해당 회의를 선택하면 다른 회의를 선택하는 것보다 빨리 끝나는 선택이 됨
        */ 
        if(fin <= conf[i].second) {
            fin = conf[i].first;
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}