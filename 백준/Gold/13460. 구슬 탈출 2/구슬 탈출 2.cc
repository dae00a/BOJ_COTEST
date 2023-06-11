#include <bits/stdc++.h>

#define P pair<int, int>

using namespace std;

int N, M, min_round = 11;
P Red, Blue, Hole;
char board[11][11];

void mv_up();
void mv_down();
void mv_left();
void mv_right();

void (*funcptr[])() = {mv_up, mv_down, mv_left, mv_right};
void dfs(int round);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++) {
            board[i][j] = str[j];
            if(str[j] == 'R') {
                Red = {i, j};
                board[i][j] = '.';
            }
            else if(str[j] == 'B') {
                Blue = {i, j};
                board[i][j] = '.';
            }
            else if(str[j] == 'O')
                Hole = {i, j};
        }
    }

    dfs(1);

    cout << (min_round <= 10 ? min_round : -1) << "\n"; 

    return 0;
}

void mv_up() {
    if(Red.first <= Blue.first) {
        while(board[Red.first-1][Red.second] != '#') {
            Red.first--;
            if(board[Red.first][Red.second] == 'O')
                break;
        }
        while(board[Blue.first-1][Blue.second] != '#') {
            // 다음 이동 칸의 위치가 빈 칸이고 Red의 위치와 같은 경우
            if(board[Blue.first-1][Blue.second] == '.' && Red.first == (Blue.first - 1) && Red.second == Blue.second)
                break;
            Blue.first--;
            if(board[Blue.first][Blue.second] == 'O')
                break;
        }
    }
    else {
        while(board[Blue.first-1][Blue.second] != '#') {
            Blue.first--;
            if(board[Blue.first][Blue.second] == 'O')
                break;
        }
        while(board[Red.first-1][Red.second] != '#') {
            if(board[Red.first-1][Red.second] == '.' && Blue.first == (Red.first - 1) && Blue.second == Red.second)
                break;
            Red.first--;
            if(board[Red.first][Red.second] == 'O')
                break;
        }
    }
}

void mv_down() {
    if(Red.first >= Blue.first) {
        while(board[Red.first+1][Red.second] != '#') {
            Red.first++;
            if(board[Red.first][Red.second] == 'O')
                break;
        }
        while(board[Blue.first+1][Blue.second] != '#') {
            if(board[Blue.first+1][Blue.second] == '.' && Red.first == (Blue.first + 1) && Red.second == Blue.second)
                break; 
            Blue.first++;
            if(board[Blue.first][Blue.second] == 'O')
                break;
        }
    }
    else {
        while(board[Blue.first+1][Blue.second] != '#') {
            Blue.first++;
            if(board[Blue.first][Blue.second] == 'O')
                break;
        }
        while(board[Red.first+1][Red.second] != '#') {
            if(board[Red.first+1][Red.second] == '.' && Blue.first == (Red.first + 1) && Blue.second == Red.second)
                break;
            Red.first++;
            if(board[Red.first][Red.second] == 'O')
                break;
        }
    }
}

void mv_left() {
    if(Red.second <= Blue.second) {
        while(board[Red.first][Red.second-1] != '#') {
            Red.second--;
            if(board[Red.first][Red.second] == 'O')
                break;
        }
        while(board[Blue.first][Blue.second-1] != '#') {
            if(board[Blue.first][Blue.second-1] == '.' && Red.first == Blue.first && Red.second == (Blue.second - 1))
                break; 
            Blue.second--;
            if(board[Blue.first][Blue.second] == 'O')
                break;
        }
    }
    else {
        while(board[Blue.first][Blue.second-1] != '#') {
            Blue.second--;
            if(board[Blue.first][Blue.second] == 'O')
                break;
        }
        while(board[Red.first][Red.second-1] != '#') {
            if(board[Red.first][Red.second-1] == '.' && Red.first == Blue.first && Blue.second == (Red.second - 1))
                break; 
            Red.second--;
            if(board[Red.first][Red.second] == 'O')
                break;
        }
    }
}

void mv_right() {
    if(Red.second >= Blue.second) {
        while(board[Red.first][Red.second+1] != '#') {
            Red.second++;
            if(board[Red.first][Red.second] == 'O')
                break;
        }
        while(board[Blue.first][Blue.second+1] != '#') {
            if(board[Blue.first][Blue.second+1] == '.' && Red.first == Blue.first && Red.second == (Blue.second + 1))
                break; 
            Blue.second++;
            if(board[Blue.first][Blue.second] == 'O')
                break;
        }
    }
    else {
        while(board[Blue.first][Blue.second+1] != '#') {
            Blue.second++;
            if(board[Blue.first][Blue.second] == 'O')
                break;
        }
        while(board[Red.first][Red.second+1] != '#') {
            if(board[Red.first][Red.second+1] == '.' && Red.first == Blue.first && Blue.second == (Red.second + 1))
                break; 
            Red.second++;
            if(board[Red.first][Red.second] == 'O')
                break;
        }
    }
}

void dfs(int round) {
    if(round > 10 || min_round <= round)
        return ;

    for(int i = 0; i < 4; i++) {
        P tmpRed = Red;
        P tmpBlue = Blue;

        funcptr[i]();

        if(tmpRed == Red && tmpBlue == Blue)
            continue;

        // Blue가 구멍에 빠진 경우
        if(Blue.first == Hole.first && Blue.second == Hole.second) {
            Red = tmpRed;
            Blue = tmpBlue;
            continue;
        }
        else if(Red.first == Hole.first && Red.second == Hole.second)
            min_round = min(min_round, round);
        else
            dfs(round + 1);
        Red = tmpRed;
        Blue = tmpBlue;
    }
}