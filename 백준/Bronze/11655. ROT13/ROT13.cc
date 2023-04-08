#include <bits/stdc++.h>

using namespace std;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    string S;
    getline(cin, S);
    int len = S.length();
    for(int i = 0; i < len; i++) {
        unsigned char c = S[i];
        if(c >= 'a' && c <= 'z') {
            c += 13;
            if(c > 'z')
                c = 'a' + (c % 'z') - 1;
        }
        else if(c >= 'A' && c <= 'Z') {
            c += 13;
            if(c > 'Z')
                c = 'A' + (c % 'Z') - 1;
        }
        cout << c;
    }

    return 0;
}