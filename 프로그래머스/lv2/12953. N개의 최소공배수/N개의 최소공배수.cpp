#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getGCD(int a, int b);
int getLCM(int a, int b);

int solution(vector<int> arr) {
    int answer = 0;
    int len = arr.size();
    int lcm = arr[0];
    
    for(int i = 1; i < len; i++)
        lcm = getLCM(lcm, arr[i]);
    
    answer = lcm;
    
    return answer;
}

int getGCD(int a, int b) {
    int ret = 1;
    
    if(b > a) {
        int tmp = a;
        a = b; b = tmp;
    }
    
    while(a > 0) {
        a = a % b;
        
        if(!a) {
            ret = b;
            break;
        }
        else {
            int tmp = a;
            a = b; b = tmp;
        }
    }
    
    return ret;
}

int getLCM(int a, int b) {
    int gcd = 1;
    
    gcd = getGCD(a, b);
    
    return (a * b / gcd);
}