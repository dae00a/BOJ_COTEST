#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> player;
map<int, int> score;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    player.push_back({0, 0});
    for(int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        player.push_back({tmp, 0});
        score[tmp] = i;
    }

    for(int i = 1; i <= (int)player.size(); i++) {
        int num = player[i].first;
        
        for(int j = 1; j <= sqrt(num); j++) {
            if(!(num % j)) {
                if(score[j]) {
                    player[i].second--;
                    player[score[j]].second++;
                    if(j * j == num)
                        continue;
                }
                if(score[num/j]) {
                    player[i].second--;
                    player[score[num/j]].second++;
                }
            }
        }
    }

    for(int i = 1; i < (int)player.size(); i++) {
        cout << player[i].second << " ";
    }
    cout << "\n";

    return 0;
}