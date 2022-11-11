#include <stdio.h>
#include <math.h>

int zero_sum5(int k) {
    int i = 1;
    int sum = 0;
    while(i) {
        if((k / pow(5, i)) > 0)
            sum += (k / pow(5, i));
        else
            break;
        i++;
    }
    return sum;
}

int zero_sum2(int k) {
    int i = 1;
    int sum = 0;
    while(i) {
        if((k / pow(2, i)) > 0)
            sum += (k / pow(2, i));
        else
            break;
        i++;
    }
    return sum;
}

int main() {
    int n, m;
    int total_2, total_5;
    int p1_2, p1_5;
    int p2_2, p2_5;
    int zero_check = 0;
    scanf("%d %d", &n, &m);

    total_2 = zero_sum2(n);
    total_5 = zero_sum5(n);
    p1_2 = zero_sum2(m);
    p1_5 = zero_sum5(m);
    p2_2 = zero_sum2(n - m);
    p2_5 = zero_sum5(n - m);

    total_2 = total_2 - p1_2 - p2_2;
    total_5 = total_5 - p1_5 - p2_5;

    while(1) {
        if(total_2 <= 0 || total_5 <= 0)
            break;
        total_2--;
        total_5--;
        zero_check++;
    }
    printf("%d", zero_check);

    return 0;
}