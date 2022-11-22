#include<iostream>
#include<vector>
using namespace std;

int N;
vector<bool> dp(1001);

int main(int argc, char *argv[]) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
	
	cin >> N;
	
	dp[1] = true; dp[2] = false; dp[3] = true;
	
	for(int i = 4; i <= N; i++) {
		if(dp[i - 3]) {
			dp[i] = false;
		}
		else {
			dp[i] = true;
		}
	}
	
	if(dp[N]) {
		cout << "SK\n";
	}
	else {
		cout << "CY\n";
	}
	
	return 0;
}