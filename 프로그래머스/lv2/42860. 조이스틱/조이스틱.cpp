#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int n = name.length();
    int answer = 0;
    
    for(int i = 0; i < name.length(); i++) {
        int tmp = name[i] - 'A';
        answer += (tmp > 13 ? 13 - tmp % 13 : tmp);
    }

    int cursor = n - 1;
    for(int i = 0; i < n; i++) {
        int j = i + 1;
        while(j < n && name[j] == 'A')
            j++;
        
        cursor = min(cursor, i + n - j + min(i, n - j));
    }
        
    answer += cursor;
     
    return answer;
}