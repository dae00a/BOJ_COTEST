#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<int> v(1000000);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> T;
    while(T--) {
    	// init
    	int max_v;
    	long long res = 0;
    	long long tmp = 0;
    	
    	v.clear();
    	
    	cin >> N;
    	for(int i = 0; i < N; i++) {
    		cin >> v[i];
    	}
    	
    	max_v = v[N-1];
    
 	   for(int i = N-1; i >= 0; i--) {
   	     if(max_v < v[i]) {
   	     	res += tmp;
   	     	tmp = 0;
   	     	max_v = v[i];
   	     }
   	     else {
   	     	tmp += (max_v - v[i]);
   	     }
 	   }
 	   
 	   cout << (res < 0 ? 0 : (res + tmp)) << "\n";
    }  

    return 0;
}