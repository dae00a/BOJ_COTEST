#include <bits/stdc++.h>

using namespace std;

typedef struct NODE {
    int val, piece;
    NODE *next = nullptr, *shortcut = nullptr;
} NODE;
  
int max_score;
int dist[10];
NODE node_map[33];
NODE *p[5];

void init();
void dfs(int round, int score);

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    for(int i = 0; i < 10; i++)
        cin >> dist[i];

    init();

    dfs(0, 0);

    cout << max_score << "\n";

    return 0;
}

void init() {
    for(int i = 0; i < 20; i++) {
        node_map[i].next = &node_map[i+1];
        node_map[i+1].val = 2 * (i + 1);
    }
    node_map[5].shortcut = &node_map[21];
    node_map[10].shortcut = &node_map[24];
    node_map[15].shortcut = &node_map[26];
    node_map[20].next = &node_map[32];

    node_map[21].next = &node_map[22];
    node_map[21].val = 13;
    node_map[22].next = &node_map[23];
    node_map[22].val = 16;
    node_map[23].next = &node_map[29];
    node_map[23].val = 19;
    node_map[24].next = &node_map[25];
    node_map[24].val = 22;
    node_map[25].next = &node_map[29];
    node_map[25].val = 24;
    node_map[26].next = &node_map[27];
    node_map[26].val = 28;
    node_map[27].next = &node_map[28];
    node_map[27].val = 27;
    node_map[28].next = &node_map[29];    
    node_map[28].val = 26;
    node_map[29].next = &node_map[30];
    node_map[29].val = 25;
    node_map[30].next = &node_map[31];
    node_map[30].val = 30;
    node_map[31].next = &node_map[20];
    node_map[31].val = 35;

    for(int i = 1; i < 5; i++)
        p[i] = &node_map[0];
}

void dfs(int round, int score) {
    if(round == 10) {
        max_score = max(max_score, score);
        return ;
    }

    for(int i = 1; i < 5; i++) {
        if(p[i]->next == nullptr)
            continue;

        NODE *tmp = p[i];

        if(p[i]->shortcut == nullptr) {    
            for(int j = 0; j < dist[round]; j++) {
                tmp = tmp->next;
                if(tmp->next == nullptr)
                    break;
            }
        }
        else {
            tmp = p[i]->shortcut;
            for(int j = 1; j < dist[round]; j++) {
                tmp = tmp->next;
                if(tmp->next == nullptr)
                    break;
            }
        }

        // 이동한 칸에 이미 다른 말이 존재하는 경우
        if(tmp->piece) 
            continue;

        NODE *prev = p[i];

        p[i]->piece = 0;
        p[i] = tmp;
        // 도착 지점이 아닌 경우
        if(p[i]->next != nullptr)
            p[i]->piece = i;

        dfs(round + 1, score + p[i]->val);

        p[i]->piece = 0;
        p[i] = prev;
        p[i]->piece = i;
    }
}