#include <bits/stdc++.h>

using namespace std;

typedef struct NODE {
    int num;
    NODE *prev = nullptr;
} NODE;

int N;
NODE seq[1000001];
vector<int> dp, loc;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        seq[i].num = tmp;
    }

    dp.push_back(seq[0].num);
    loc.push_back(0);
    for(int i = 1; i < N; i++) {
        int val = seq[i].num;
        unsigned int lower = lower_bound(dp.begin(), dp.end(), val) - dp.begin();

        if(lower < dp.size()) {
            if(lower > 0)
                seq[i].prev = &seq[loc[lower-1]];
            dp[lower] = val;
            loc[lower] = i;
        }
        else {
            seq[i].prev = &seq[loc[dp.size()-1]];
            dp.push_back(val);
            loc.push_back(i);
        }
    }

    vector<int> answer;
    for(NODE *p = &seq[loc[dp.size()-1]]; p != nullptr; p = p->prev)
        answer.push_back(p->num);
    reverse(answer.begin(), answer.end());

    cout << dp.size() << "\n";
    for(unsigned int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout << "\n";

    return 0;
}