#include <bits/stdc++.h>
using namespace std;

bool comp(string &a, string &b) {
    if(a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    int pbsize = phone_book.size();
    set<string> s;
    
    sort(phone_book.begin(), phone_book.end(), comp);
    
    for(int i = 0; i < pbsize; i++) {
        int len = phone_book[i].length();
        for(int j = 1; j <= len; j++) {
            if(s.find(phone_book[i].substr(0, j)) != s.end()) {
                return false;
            }
        }
        s.insert(phone_book[i]);
    }
    
    return answer;
}