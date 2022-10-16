#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int main() { 
    cin >> N >> K;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << v[K-1];
}