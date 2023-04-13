#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
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
    
    while(!st.empty()) {
        if(n - k < st.size()){
            st.pop();
            continue;
        }
        answer = st.top() + answer;
        st.pop();    
    }
    
    return answer;
}