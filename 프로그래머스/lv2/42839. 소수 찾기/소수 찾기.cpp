#include <bits/stdc++.h>
using namespace std;

int N, answer, len;
string nums;
bool check[100000000] = {1, 1, }, used[8];

void permutation(int cnt, string s);

int solution(string numbers) {
    len = numbers.length();
    nums = numbers;
    for(int i = 1; i <= len; i++) {
        string s;
        N = i;
        permutation(0, s);
    }
    
    return answer;
}

void permutation(int cnt, string s) {
    if(cnt == N) {
        int val = stoi(s);
        bool flag = true;
        
        if(check[val])
            return ;
        
        for(int i = 2; i * i <= val; i++) {
            if(!(val % i)) {
                flag = false;
                break;
            }
        }
        
        if(flag)
            answer++;
        check[val] = true;
        return ;
    }
    
    for(int i = 0; i < len; i++) {
        if(used[i])
            continue;
        used[i] = true;
        permutation(cnt + 1, s + nums[i]);
        used[i] = false;    
    }
}