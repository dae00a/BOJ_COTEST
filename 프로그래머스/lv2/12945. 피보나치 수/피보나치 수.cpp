#include <string>
#include <vector>

#define RMD 1234567

using namespace std;

int F[100001];

int fibo(int n);

int solution(int n) {
    int answer = 0;
    
    answer = fibo(n);
    
    return answer;
}

int fibo(int n) {
    if(n <= 1)
        return n;
    if(!F[n-1])
        F[n-1] = fibo(n-1) % RMD;
    if(!F[n-2])
        F[n-2] = fibo(n-2) % RMD;
    return (F[n] = (F[n-1] + F[n-2]) % RMD);    
}