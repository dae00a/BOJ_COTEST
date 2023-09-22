#include<bits/stdc++.h>

int N;

using namespace std;

int main() {
	cin >> N;

	stack<pair<int, int>> st; 

	int ans = 0;

	for(int n = 0; n < N; n++) {
		int p;
		cin >> p;

		if(p) {
			int A, T;
			cin >> A >> T;
			
			st.push({A, T});
		}

		if(!st.empty()) {
			st.top().second--;

			if(st.top().second <= 0) {
				ans += st.top().first;
				st.pop();
			}
		}
		
	}

	cout << ans << "\n";
}