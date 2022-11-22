#include <bits/stdc++.h>
#include <string>
using namespace std;

string expr;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    getline(cin, expr);

    bool minus = false;
    int res = 0, tmp = 0;
    string num;

    for(int i = 0; i < expr.length(); i++) {
        char figure = expr.at(i); 

        if(figure >= '0' && figure <= '9') {
            num.push_back(figure);
        }
        else {
            tmp = stoi(num);

            if(minus) {
                res -= tmp;
            }
            else {
                res += tmp;
            }

            num.clear();
        }

        if(figure == '-') {
            minus = true;
        }
    }

    cout << res + (minus ? -1 : 1) * stoi(num) << "\n";

    return 0;
}