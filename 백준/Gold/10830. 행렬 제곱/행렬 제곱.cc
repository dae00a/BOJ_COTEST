#include <bits/stdc++.h>

#define MOD 1000

using namespace std;

long long N, B;
vector<vector<long long>> mat(5, vector<long long> (5));

vector<vector<long long>> matMul(vector<vector<long long>> &A, long long k);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> N >> B;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mat[i][j];
            mat[i][j] %= MOD;
        }
    }

    vector<vector<long long>> ans = matMul(mat, B);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

vector<vector<long long>> matMul(vector<vector<long long>> &A, long long k) {
    if(k == 1) 
        return A;

    vector<vector<long long>> ret(5, vector<long long> (5, 0));
    vector<vector<long long>> tmp = matMul(A, k / 2);

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            for(int i = 0; i < N; i++) {
                ret[r][c] += (tmp[r][i] * tmp[i][c] % MOD);
                ret[r][c] %= MOD;
            }
        }
    }

    if(k % 2) {
        vector<vector<long long>> tmpret(5, vector<long long> (5, 0));
      
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                for(int i = 0; i < N; i++) {
                    tmpret[r][c] += (ret[r][i] * A[i][c] % MOD);
                    tmpret[r][c] %= MOD;
                }
            }
        }    

        ret = tmpret;
    }

    return ret;
}