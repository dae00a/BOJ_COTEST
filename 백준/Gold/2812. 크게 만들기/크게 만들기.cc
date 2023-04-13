#include <bits/stdc++.h>
using namespace std;

void solution(string &number, int k);

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    int N, K;
    string s;
    
    cin >> N >> K >> s;
    solution(s, K);
    
    return 0;
}

void solution(string &number, int k) {
    string answer = "";
    int n = number.length();
    stack<char> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && k) {
            if(st.top() >= number[i])
                break;
            k--;
            st.pop();
        }
        st.push(number[i]);
    }
    
    while(k) {
        st.pop();
        k--;
    }
    while(!st.empty()) {
        answer += st.top();
        st.pop();    
    }
    reverse(answer.begin(), answer.end());
    
    cout << answer << "\n";
}