#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, vector<int>> childrenof;

void bfs() {
    vector<int> counts;
    queue<int> q;
    q.push(1);
    int count = 0;
    int levelend = 1;
    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        if (childrenof[parent].empty()) {
            count++;
        } else {
            for (int i : childrenof[parent]) q.push(i);
        }
        if (parent == levelend) {
            counts.push_back(count);
            count = 0;
            if (!q.empty()) levelend = q.back();
        }
    }
    cout << counts[0];
    for (int i = 1; i < counts.size(); ++i) cout << ' ' << counts[i];
}

int main(int argc, char const *argv[]) {
    cin >> N;
    if (N == 0) return 0;

    cin >> M;
    for (int i = 0; i < M; i++) {
        int ID, K;
        cin >> ID >> K;
        childrenof[ID] = vector<int>(K);
        auto &children = childrenof[ID];
        for (int i = 0; i < K; i++) {
            cin >> children[i];
        }
    }
    bfs();
    return 0;
}
