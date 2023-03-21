#include <bits/stdc++.h>

using namespace std;

int N;
int ch[27], maxVal;
string str[10];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> str[i];

        int len = str[i].length() - 1;
        int tmpower = 1;

        for(int j = len; j >= 0; j--) {
            ch[str[i][j] - 'A'] += tmpower;
            tmpower *= 10;
        }
    }
    
    sort(ch, ch+27, greater<int>());

    int op = 9;
    for(int i = 0; ch[i] != 0; i++)
        maxVal += (ch[i] * op--);

    cout << maxVal << "\n";

    return 0;
}