#include <bits/stdc++.h>

using namespace std;

int N;
int fname[27];
const char a = 'a';

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    while(N--) {
        string s;
        cin >> s;
        fname[s[0]-a]++;
    }

    bool flag = false;
    for(char i = 'a'; i <= 'z'; i++) {
        if(fname[i-a] >= 5) {
            flag = true;
            cout << i;
        }
    }

    if(!flag)
        cout << "PREDAJA\n";
    else
        cout << "\n";

    return 0;
}