#include <bits/stdc++.h>

#define MAX_PLAYER 100000
#define MAX_NUM 1000000

using namespace std;

int N, M;
int player[MAX_PLAYER+1], score[MAX_NUM+1];
bool card[MAX_NUM+1];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        player[i] = tmp;
        card[tmp] = true;

        M = max(M, tmp);
    }

    for(int i = 0; i < N; i++) {
        for(int j = player[i] * 2; j <= M; j += player[i]) {
            if(card[j]) {
                score[player[i]]++;
                score[j]--;
            }
        }
    }

    for(int i = 0; i < N; i++)
        cout << score[player[i]] << " ";
    cout << "\n";

    return 0;
}