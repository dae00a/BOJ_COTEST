#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer, len = s.length(), cnt = 0;
    bool flag;
    
    for(int i = 0; i < len; i++) {
        stack<char> st;
        flag = true;
        
        for(int j = i; j < i + len; j++) {
            char c = s[j%len];
            if((c == '(') || (c == '{') || (c == '['))
                st.push(c);
            else if(st.empty()) {
                flag = false;
                break;
            }
            else {
                if((st.top() == '(' && c == ')') || (st.top() == '{' && c == '}') ||
                    (st.top() == '[' && c == ']'))
                    st.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(flag && st.empty())
            cnt++;
    }
    
    answer = cnt;
    return answer;
}