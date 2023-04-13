#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int biggest = 0;
    int idx = 0;

    for (int i = 0; i < number.length(); ++i) {
        if (biggest < number[i]) {
            biggest = number[i];
            idx = i;
        }

        if (i == k) {
            i = idx;
            k++;
            answer.push_back(biggest);
            biggest = 0;
        }
    }
    
    return answer;
}