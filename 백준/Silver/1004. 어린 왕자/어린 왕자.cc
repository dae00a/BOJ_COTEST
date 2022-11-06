#include <bits/stdc++.h>
using namespace std;

int T, N;
int cnt;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int x1, y1, x2, y2, cx, cy, r;
    
    cin >> T;
    while(T--) {
        // 초기화
        cnt = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> N;

        for(int i = 0; i < N; i++) {
            cin >> cx >> cy >> r;

            // 원(행성계)의 중점에서 출발점부터 도착점까지의 직선 거리까지의 수직 거리
            int d = abs((y2 - y1) * cx - (x2 - x1) * cy -
                        (y2 - y1) * x1 + (x2 - x1) * y1)
                    / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            
            // 출발점부터 도착점까지의 직선이 원(행성계)을 통과하는 경우
            if(d < r) {
                // 출발점 또는 도착점 중 하나만 원(행성계) 내부에 위치하는 경우
                // 즉, 행성계에 진입했으나 해당 행성계를 벗어나지 않은 경우
                int d_depart_square = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
                int d_arrive_square = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
                if(d_depart_square < r * r && d_arrive_square < r * r) {
                    continue;
                }
                else if(d_depart_square < r * r || d_arrive_square < r * r) {
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}