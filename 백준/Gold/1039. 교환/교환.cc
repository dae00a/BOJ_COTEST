#include <bits/stdc++.h>

using namespace std;

int N, K;
int maxVal = 0;
bool check[11][1000000];

void dfs(int cnt, vector<int> &v);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> K;

    vector<int> tmp;
    stack<int> s;
    while(N) {
        int r = N % 10;
        s.push(r);
        N /= 10;
    }
    while(!s.empty()) {
        tmp.push_back(s.top());
        s.pop();
    }

    dfs(0, tmp);

    cout << (maxVal ? maxVal : -1) << "\n";

    return 0;
}

void dfs(int cnt, vector<int> &v) {
    if(v[0] == 0)
        return ;
    
    int val = 0;
    int size = v.size();
    for(int i = size - 1; i >= 0; i--)
        val += v[i] * pow(10, size - 1 - i);

    if(check[cnt][val])
        return;

    check[cnt][val] = true;

    if(cnt == K) {
        maxVal = max(maxVal, val);
        return ;
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            swap(v[i], v[j]);
            dfs(cnt + 1, v);
            swap(v[i], v[j]);
        }
    }
}