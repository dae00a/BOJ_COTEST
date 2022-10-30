/*
    첫번째 명단을 set에 삽입한 후 두번째 명단과 일치하는 이름을 vector에 삽입
*/
#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

set<string> s;
vector<string> v;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    string str;
    
    // 첫번째 명단 set에 삽입
    for(int i = 0; i < N; i++) {
        cin >> str;
        s.insert(str);
    }
    // 두번째 명단의 이름이 첫번째 명단에 존재하는지 여부
    for(int i = 0; i < M; i++) {
        cin >> str;
        if(s.find(str) != s.end()) {
            v.push_back(str);
        }
    }

    sort(v.begin(), v.end());

    int vlen = v.size();

    cout << vlen << "\n";
    for(int i = 0; i < vlen; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}