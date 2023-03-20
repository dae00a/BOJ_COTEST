#include <bits/stdc++.h>

using namespace std;

int N;
int plane[10][10], cnt;
const int dx[2] = {0, 1}, dy[2] = {1, 0};
bool used[10][10], flag;

bool isPossible(int r, int c, int v);
void printPlane();
void dfs(int dep);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    while(1) {
        int U, V;
        string LU, LV, L; 

        for(int i = 1; i < 10; i++) {
            for(int j = 1; j < 10; j++) {
                plane[i][j] = 0;
                used[i][j] = 0;
            }
        }
        flag = false;
        cnt++;
        
        cin >> N;

        if(N == 0)
            break;

        for(int i = 0; i < N; i++) {
            cin >> U >> LU >> V >> LV;
            plane[LU[0]-'A'+1][LU[1]-'0'] = U;
            plane[LV[0]-'A'+1][LV[1]-'0'] = V;
            used[U][V] = true;
        } 

        for(int i = 1; i < 10; i++) {
            cin >> L;
            plane[L[0]-'A'+1][L[1]-'0'] = i;
        }

        dfs(N);
    }

    return 0;
}

bool isPossible(int r, int c, int v) {
    for(int i = 1; i < 10; i++) {
        if(plane[r][i] == v)
            return false;
    }

    for(int i = 1; i < 10; i++) {
        if(plane[i][c] == v)
            return false;
    }

    int x = r / 3, xm = r % 3;
    if(!xm)
        x--;
    x = x * 3 + 1;
    int y = c / 3, ym = c % 3;
    if(!ym)
        y--;
    y = y * 3 + 1;
    for(int i = x; i < x + 3; i++) {
        for(int j = y; j < y + 3; j++) {
            if(plane[i][j] == v)
                return false;
        }
    }

    return true;
}

void printPlane() {
    cout << "Puzzle " << cnt << "\n";
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            cout << plane[i][j];
        }
        cout << "\n";
    }
}

bool isComplete() {
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            if(!plane[i][j])
                return false;
        }
    }

    return true;
}

void dfs(int dep) {
    if(flag)
        return ;

    if(dep >= 36) {
        if(isComplete) {
            printPlane();
            flag = true;
        } 
        return ;
    }

    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            if(!plane[i][j]) {
                for(int k = 0; k < 2; k++) {
                    if((i + dx[k] <= 0) || (j + dy[k] <= 0) || (i + dx[k] > 9) || (j + dy[k] > 9) || plane[i+dx[k]][j+dy[k]]) 
                        continue;
                    for(int u = 1; u < 10; u++) {
                        for(int v = u + 1; v < 10; v++) {
                            if(used[u][v] || used[v][u])
                                continue;
                            used[u][v] = true;

                            if(isPossible(i, j, u) && isPossible(i + dx[k], j + dy[k], v)) {
                                plane[i][j] = u;
                                plane[i+dx[k]][j+dy[k]] = v;
                                dfs(dep + 1);
                                plane[i][j] = 0;
                                plane[i+dx[k]][j+dy[k]] = 0;
                            }
                            
                            if(isPossible(i, j, v) && isPossible(i + dx[k], j + dy[k], u)) {
                                plane[i][j] = v;
                                plane[i+dx[k]][j+dy[k]] = u;
                                dfs(dep + 1);
                                plane[i][j] = 0;
                                plane[i+dx[k]][j+dy[k]] = 0;
                            }

                            used[u][v] = false;
                        }
                    }
                }
                return ;
            }
        }
    }
}