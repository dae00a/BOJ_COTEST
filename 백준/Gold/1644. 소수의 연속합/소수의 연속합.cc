#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N;
vector<bool> v(4000001);
vector<int> prime_num;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int sum = 0, cnt = 0, front = 0;

    cin >> N;

    for(int i = 2; i < (int)sqrt(N) + 1; i++) {
        int p = 2;
        
        // v[i] true: non prime number
        if(v[i]) {
        	continue;
        }
        
        while(i * p <= N) {
            // if not specify that v[i] is prime
            if(!v[i*p]) {
                v[i*p] = true;
            }
            p++;
        }
    }
    
    for(int i = 2; i <= N; i++) {
    	if(!v[i]) {
    		prime_num.push_back(i);
    	}
    }   
    
    for(int i = 0; i < prime_num.size(); i++) {
    	sum += prime_num[i];
    	
    	while(sum > N) {
    		sum -= prime_num[front++];
    	}
    	
    	// 연속합이 N과 같은 경우
   	 if(sum == N) {
    		cnt++;
		}
    }

    cout << cnt << "\n";

    return 0;
}