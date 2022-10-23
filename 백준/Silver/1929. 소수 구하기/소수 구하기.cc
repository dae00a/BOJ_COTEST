/*
    소수 출력.
    소수는 약수가 1을 제외한 자기 자신 밖에 없는 수.
    2부터 N까지 순회하면서 방문한 수가 소수인지 판단.
    k의 약수는 2부터 k의 제곱근까지 나누었을 때 
    나머지가 0인 경우 약수가 존재하므로 소수가 아니다.
*/
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int M, N;
    cin >> M >> N;
    
    // M부터 N까지 순회
    for(int i = M; i <= N; i++) {
        int tmp = sqrt(i);
        int j = 2;

        // M부터 N까지의 값 중 제곱근까지 약수 탐색
        for(; j <= tmp; j++) {
            // 약수가 존재하는 경우
            if(i % j == 0) {
                break;
            }
        }
        // 약수가 존재하지 않는 경우 출력
        if(i != 1 && j > tmp) {
            cout << i << "\n";
        }
    }

    return 0;
}