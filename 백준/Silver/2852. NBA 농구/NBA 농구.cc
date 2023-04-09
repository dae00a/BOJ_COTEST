#include <bits/stdc++.h>

using namespace std;

int N, score[3], winTime[3];

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int prev_time = 0;

    cin >> N;
    for(int i = 0; i <= N; i++) {
        int team = 1, cur_time = 48 * 60;
        string s;

        if(i < N) {
            cin >> team >> s;
            cur_time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        }
            
        
        if(score[3-team] < score[team])
            winTime[team] += (cur_time - prev_time);
        else if(score[team] < score[3-team])
            winTime[3-team] += (cur_time - prev_time);

        prev_time = cur_time;
        score[team]++;
    }

    string t1, t2;
    cout << right << setfill('0') << setw(2) << (winTime[1] / 60) << ":" 
         << right << setfill('0') << setw(2) << (winTime[1] % 60) << "\n";
    cout << right << setfill('0') << setw(2) << (winTime[2] / 60) << ":" 
         << right << setfill('0') << setw(2) << (winTime[2] % 60) << "\n";

    return 0;
}