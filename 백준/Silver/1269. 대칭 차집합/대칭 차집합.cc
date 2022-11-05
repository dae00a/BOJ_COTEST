#include <bits/stdc++.h>
#include <set>
using namespace std;

int N, M;
set<int> A;

int main() {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
	
	int tmp = 0;
	int B_cnt = 0;
	
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> tmp;
		A.insert(tmp);
	}
	for(int i = 0; i < M; i++) {
		cin >> tmp;
	
		if(A.find(tmp) != A.end()) {
			A.erase(tmp);
		}
		else {
			B_cnt++;
		}
	}
	
	cout << A.size() + B_cnt << "\n";
	
	return 0;
}