#include <bits/stdc++.h>

using namespace std;

long f_mul(long s) {return (s * s);}
long f_add(long s) {return (s + s);}
long f_sub(long s) {return (s - s);}
long f_div(long s) {return (s / s);}
long (*func_ptr[])(long) = {f_mul, f_add, f_sub, f_div,};
char func_op[] = {'*', '+', '-', '/',};

bool bfs(long s, long t);

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    long s, t;
    cin >> s >> t;

    if(s == t)
        cout << 0 << "\n";
    else if(!bfs(s, t)) 
        cout << -1 << "\n";

    return 0;
}

bool bfs(long s, long t) {
    bool res = false;

    set<long> numSet;
    queue<pair<long, string>> q;
    q.push({s,""});
    numSet.insert(s);

    while(!q.empty()) {
        long cur_s = q.front().first;
        string str = q.front().second;
        q.pop();

        if(cur_s == t) {
            res = true;
            cout << str << "\n";
            break;
        }

        long func_size = sizeof(func_ptr) / sizeof(*func_ptr);
        for(long i = 0; i < func_size; i++) {
            long new_s = func_ptr[i](cur_s);
       
            if(numSet.find(new_s) != numSet.end())
                continue;
            if(new_s <= 0 || new_s > 1e9)
                continue;
            
            numSet.insert(new_s);
            str.push_back(func_op[i]);
            q.push({new_s, str});
            str.pop_back();
        }       
    }

    return res;
}