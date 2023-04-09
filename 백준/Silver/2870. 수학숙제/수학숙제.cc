#include <bits/stdc++.h>

using namespace std;

int N;

bool comp(string a, string b) {
    if(a.length() == b.length()) {
        return (a < b);
    }
    return (a.length() < b.length());
}

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    vector<string> v;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if('0' <= s[i] && s[i] <= '9') {
                string tmp;
                int j = i;
                while(j < len && s[j] == '0')
                    j++;
                while(j < len && '0' <= s[j] && s[j] <= '9') {
                    tmp.push_back(s[j]);
                    j++;
                }

                if(tmp.empty())
                    v.push_back("0");
                else
                    v.push_back(tmp);
                i = j;
            }
        }
    }

    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";

    return 0;
}