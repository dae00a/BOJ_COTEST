#include <bits/stdc++.h>

using namespace std;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 0; i < len / 2; i++) {
        if(s[i] != s[len - 1 - i]) {
            cout << "0\n";
            return 0;
        }
    }

    cout << "1\n";

    return 0;
}