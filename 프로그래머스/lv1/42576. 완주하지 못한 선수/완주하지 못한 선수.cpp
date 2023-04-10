#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mmap;
    
    int psize = participant.size(), csize = completion.size();
    for(int i = 0; i < csize; i++)
        mmap[completion[i]]++;
    for(int i = 0; i < psize; i++) {
        if(mmap[participant[i]] <= 0) {
            answer = participant[i];
            break;
        }
        mmap[participant[i]]--;
    }
    
    return answer;
}