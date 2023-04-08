#include <bits/stdc++.h>

using namespace std;

int N;
string pattern;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> pattern;
    
    string lp, rp;
    for(int i = 0; i < pattern.length(); i++) {
        if(pattern[i] == '*') {
            lp = pattern.substr(0, i);
            rp = pattern.substr(i+1, pattern.length()-1);
            break;
        }
    }
    
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        
        bool flag = true;
        int slen = s.length(), lplen = 0, rplen = 0;
        if(!lp.empty()) {
            lplen = lp.length();
            for(int i = 0; i < lplen; i++) {
                if(lp[i] != s[i])
                    flag = false;
            }
        }
        if(!rp.empty()) {
            rplen = rp.length();
            for(int i = 0; i < rplen; i++) {
                if(rp[rplen-1-i] != s[slen-1-i])
                    flag = false;
            }
        }

        if(flag && (lplen + rplen) <= slen)
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}