#include <bits/stdc++.h>

#define RGB 3
#define MAX_NUM 1000
#define MAX_COST 1e6

using namespace std;

int N;
int house[MAX_NUM][RGB], dp[RGB][MAX_NUM][RGB];
int minCost = (int)MAX_COST, flag;

void recursion(int cnt, int color);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < RGB; j++) {
            cin >> house[i][j];
            if(i == N - 1) {
                for(int k = 0; k < RGB; k++)
                    dp[k][i][j] = house[i][j];
            }
        }
    }

    for(int i = 0; i < RGB; i++) {
        recursion(0, i);
        minCost = min(minCost, dp[i][0][i]);
        flag++;
    }

    cout << minCost << "\n";

    return 0;
}

void recursion(int cnt, int color) {
    int diffColor1 = dp[flag][cnt+1][(color+1)%RGB];
    int diffColor2 = dp[flag][cnt+1][(color+2)%RGB];

    if(diffColor1 && diffColor2) {
        if(cnt == N - 2) {
            if((color + 1) % RGB == flag) {
                diffColor1 = MAX_COST;       
            }
            else if((color + 2) % RGB == flag) {
                diffColor2 = MAX_COST;
            }
        }
        dp[flag][cnt][color] = house[cnt][color] + min(diffColor1, diffColor2);
        return ;
    }
    else {
        if(!dp[flag][cnt+1][(color+1)%RGB]) {
            recursion(cnt + 1, (color + 1) % RGB);
            diffColor1 = dp[flag][cnt+1][(color+1)%RGB];
        }
        if(!dp[flag][cnt+1][(color+2)%RGB]) {
            recursion(cnt + 1, (color + 2) % RGB);
            diffColor2 = dp[flag][cnt+1][(color+2)%RGB];
        }
            
        dp[flag][cnt][color] = house[cnt][color] + min(diffColor1, diffColor2);
    }
}