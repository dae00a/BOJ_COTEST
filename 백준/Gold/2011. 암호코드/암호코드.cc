#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int len;
string code;
// 숫자의 위치로 획득한 값 dp에 저장.
//vector<vector<int>> dp(5001, vector<int> (5001, 0));
vector<int> dp(5001);

void get_cases(int t);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    getline(cin, code);

    len = code.length();
    int init_num = 0;

    // 코드 맨 뒷자리 추출
    if(len <= 1) {
        init_num = stoi(code);
    }
    else {
        init_num = stoi(code.substr(len-2, 2));
    }
    // 코드 맨 뒷자리의 해석의 경우의 수
    if(init_num == 10 || init_num == 20) {
        dp[1] = 1;
    }
    else if(init_num >= 1 && init_num <= 9) {
        dp[0] = 1;
    }
    else if(init_num >= 11 && init_num <= 26) {
        dp[0] = 1; dp[1] = 2;
    }
    else if((init_num % 10) != 0) {
        dp[0] = 1; dp[1] = 1;
    } 

    /* 치환값 초기화 11,12,.. -> 경우의 수가 두 가지
    for(int i = 10; i <= 26; i++) {
        if(i % 10 != 0) {
            alph[i]++;
        }
    }
    */
    // 재귀로 i부터 j까지의 코드 해석의 경우의 수를 dp[i][j]에 저장.
    for(int i = 2; i < len; i++) {
        get_cases(i);
    }

    cout << dp[len-1] << "\n";
    
    return 0;
}

void get_cases(int t) {
    // 뒤에서 t번째 코드의 두 자릿수가 유효한 숫자인 경우
    // 해당 두자리를 제외한 나머지 뒤 자리의 경우의 수를 추출
    int num = stoi(code.substr(len-t-1, 2));
    if(num >= 10 && num <= 26) {
        dp[t] += dp[t-2];
    }
    // 뒤에서 t번째 코드의 한 자릿수가 유효한 숫자인 경우
    // 해당 한자리를 제외한 나머지 뒤 자리의 경우의 수를 추출
    num = stoi(code.substr(len-t-1, 1));
    if(num >= 1 && num <= 9) {
        dp[t] += dp[t-1];
    }

    if(dp[t] >= 1000000) {
        dp[t] %= 1000000;
    }
}