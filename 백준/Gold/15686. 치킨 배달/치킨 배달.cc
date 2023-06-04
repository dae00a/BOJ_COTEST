#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N, M;
int city[50][50];
int min_chicken_len = INT_MAX - 1;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> pick;

void combination(int cnt, int next);
void get_chicken_len();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> city[i][j];
            if(city[i][j] == 1)
                house.push_back({i, j});
            if(city[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    combination(0, 0);

    cout << min_chicken_len << "\n";

    return 0;
}

void combination(int cnt, int next) {
    if(cnt == M) {
        get_chicken_len();
        return ;
    }

    for(int i = next; i < chicken.size(); i++) {
        pick.push_back(chicken[i]);
        combination(cnt + 1, i + 1);
        pick.pop_back();
    }
}

void get_chicken_len() {
    int chicken_len;
    int len;
    int sum = 0;
    for(int i = 0; i < house.size(); i++) {
        chicken_len = 101;
        for(int j = 0; j < pick.size(); j++) {
            len = abs(house[i].first - pick[j].first) + abs(house[i].second - pick[j].second);
            if(len < chicken_len)
                chicken_len = len;
        }
        sum += chicken_len;
    }

    if(sum < min_chicken_len)
        min_chicken_len = sum;
}