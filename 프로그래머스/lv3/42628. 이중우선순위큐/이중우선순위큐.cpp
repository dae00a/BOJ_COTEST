#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    unordered_map<int, int> hmap;
    int size = operations.size();
    
    for(int i = 0; i < size; i++) {
        if(operations[i][0] == 'I') {
            int num = stoi(operations[i].substr(2,operations[i].length()));
            hmap[num]++;
            max_heap.push(num);
            min_heap.push(num);
        }
        else {
            if(operations[i][2] == '1') {
                while(!max_heap.empty() && hmap[max_heap.top()] <= 0) {
                    max_heap.pop();
                }
                if(!max_heap.empty()) {
                    hmap[max_heap.top()]--;
                    max_heap.pop();
                }
            }
            else {
                while(!min_heap.empty() && hmap[min_heap.top()] <= 0) {
                    min_heap.pop();
                }
                if(!min_heap.empty()) {
                    hmap[min_heap.top()]--;
                    min_heap.pop();
                }
            }
        }
    }
    
    while(!max_heap.empty() && hmap[max_heap.top()] <= 0) {
        max_heap.pop();
    }
    while(!min_heap.empty() && hmap[min_heap.top()] <= 0) {
        min_heap.pop();
    }
    
    if(max_heap.empty())
        answer.push_back(0);
    else
        answer.push_back(max_heap.top());
    if(min_heap.empty())
        answer.push_back(0);
    else
        answer.push_back(min_heap.top());
    
    return answer;
}