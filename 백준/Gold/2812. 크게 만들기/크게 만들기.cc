#include <bits/stdc++.h>
using namespace std;

void solution(string number, int k);

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    int N, K;
    string s;
   
    cin >> N >> K;
    cin >> s;
    
    solution(s, K);
    
    return 0;
}

void solution(string number, int k) {
    string answer = "";
    answer = number.substr(k); 
    for(int i = k - 1; i >= 0; i--) {
        int j = 0;
        while(1) {
            if(number[i] >= answer[j]) {
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
            }
            else
                break;
        }
    }
    
    cout << answer << "\n";
}
