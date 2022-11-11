#include <bits/stdc++.h>
#include <vector>
using namespace std;

int T;
int N, K;
vector<int> dp(10001);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

	int cost;

    cin >> T;
    while(T--) {
    	// init
    	for(int i = 0; i <= 10000; i++) {
    		dp[i] = 0;
    	}
    	dp[0] = 1;
    	
    	cin >> N;
    
 	   for(int i = 0; i < N; i++) {
   	     cin >> cost;
	        for(int j = 1; j <= 10000; j++) {
         	   if(j - cost >= 0) {
         	   	dp[j] += dp[j - cost];
         	   }
       	 }
 	   }
 	   
		cin >> K;
 	   cout << dp[K] << "\n";
    }  

    return 0;
}