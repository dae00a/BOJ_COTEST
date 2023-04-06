#include<bits/stdc++.h>

using namespace std;

int dep[20001];

int bfs(int a, int b);

int main(int argc, char** argv) {

	int test_case;
	int T;
	int n = 1;
	for(int i = 1; n <= 20000; i++) {
		int k = n + i;
		while(n <= 20000 && n < k) {
			dep[n] = i;
			n++;
		}
	}

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case) {
		int a, b;
		cin >> a >> b;
		
		int ans = 0;
		if(a != b) {
			if(b < a) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			ans = bfs(a, b);
		}
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}

int bfs(int a, int b) {
	if(dep[a] == dep[b])
		return b - a;
	
	int lv = a, rv = a, dist = dep[b] - dep[a];
	while(dep[lv] != dep[b]) {
		lv += dep[lv];
		rv += (dep[rv] + 1);
	}

	if(b < lv)
		dist += (lv - b);
	else if(rv < b)
		dist += (b - rv);
	return dist;
}