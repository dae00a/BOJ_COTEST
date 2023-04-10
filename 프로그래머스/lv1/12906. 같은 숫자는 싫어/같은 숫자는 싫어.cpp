#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int arr_size = arr.size();
    for(int i = 0; i < arr_size; i++) {
        if(answer.empty() || answer.back() != arr[i])
            answer.push_back(arr[i]);
    }
    
    return answer;
}