#include <bits/stdc++.h>
using namespace std;

int T;

int main(void) {	
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
	long long x;
	long long y;
	long long result;
    
    cin >> T;
    while(T--) {
        cin >> x >> y;
		if (y - x == 1) {
            result = 1;
        }
		else {
			for (long long j = sqrt(y - x) - 1; j <= sqrt(y - x) + 1; j++) {
				if (j*j < y - x && y - x <= j * (j + 1)) {
                    result = 2 * j;
                }	
				else if (j*(j + 1) < y - x && y - x <= (j + 1)*(j + 1)) {
                    result = 2 * j + 1;
                }	
			}
		}
        cout << result << "\n";
		result = 0;
	}

	return 0;
}