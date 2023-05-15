#include <bits/stdc++.h>

using namespace std;

int K;
vector<deque<bool>> gear(5);

void rotate(int n, int r);
void rotate_left(int n, int r);
void rotate_right(int n, int r);
void solution();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    for(int i = 1; i <= 4; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < 8; j++) {
            gear[i].push_back(str[j] - '0');
        }
    }

    cin >> K;
    while(K--) {
        int loc, dirt;
        cin >> loc >> dirt; 
        rotate_left(loc - 1, dirt * -1);
        rotate_right(loc + 1, dirt * -1);  
        rotate(loc, dirt);
    }

    solution();

    return 0;
}

void rotate(int n, int r) {
    if(r == 1) {
        bool tmp = gear[n].back();
        gear[n].pop_back();
        gear[n].push_front(tmp);
    }
    else {
        bool tmp = gear[n].front();
        gear[n].pop_front();
        gear[n].push_back(tmp);
    }
}

void rotate_left(int n, int r) {
    if(n <= 0)
        return ;
    if(gear[n][2] == gear[n+1][6])
        return ;
    
    rotate_left(n - 1, r * -1);
    rotate(n, r);
}

void rotate_right(int n, int r) {
    if(n > 4) 
        return ;
    if(gear[n][6] == gear[n-1][2]) 
        return ;

    rotate_right(n + 1, r * -1);
    rotate(n, r);
}

void solution() {
    int answer = 0;
    for(int i = 1; i <= 4; i++) {
        if(gear[i].front())
            answer += (int)pow(2, i - 1);
    }

    cout << answer << "\n";
}