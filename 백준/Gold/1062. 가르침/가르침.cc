#include <bits/stdc++.h>

using namespace std;

int N, K;
int word[51], maxWords;

void dfs(int next, int cnt, int checked);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int len = s.length();
        for(int j = 0; j < len; j++)
            word[i] |= (1 << s[j] - 'a');
    }

    if(K < 5)
        cout << "0\n";
    else if(K >= 26)
        cout << N << "\n";
    else {
        int checked = 0;

        checked |= (1 << 'a' - 'a');
        checked |= (1 << 'c' - 'a');
        checked |= (1 << 'n' - 'a');
        checked |= (1 << 't' - 'a');
        checked |= (1 << 'i' - 'a');
    
        dfs(0, 5, checked);
    
        cout << maxWords << "\n";
    }

    return 0;
}

void dfs(int next, int cnt, int checked) {
    if(cnt == K) {
        int words = 0;

        for(int i = 0; i < N; i++) {
            if(word[i] == (word[i] & checked))
                words++;
        }

        maxWords = max(maxWords, words);
        return ;
    }

    for(int i = next; i < 26; i++) {
        if(!(checked & (1 << i))) {
            checked |= (1 << i);
            dfs(i + 1, cnt + 1, checked);
            checked &= ~(1 << i);
        }
    }
}