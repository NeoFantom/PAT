#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int N, M;  // records, memory
    vector<int> records;

    typedef priority_queue<int, vector<int>, greater<int>> pq;
    pq q1;
    pq q2;
    pq *q = &q1;
    pq *wait = &q2;

    vector<vector<int>> runs;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        int t;
        scanf("%d", &t);
        records.push_back(t);
    }

    int runid = 0;
    runs.push_back(vector<int>());

    for (int j = 0; j < M; ++j) q->push(records[j]);
    for (int i = M; i < N; ++i) {
        if (records[i] >= q->top()) {
            runs[runid].push_back(q->top());
            q->pop();
            q->push(records[i]);
        } else {
            runs[runid].push_back(q->top());
            q->pop();
            wait->push(records[i]);
            if (wait->size() == M) {
                swap(q, wait);
                runs.push_back(vector<int>());
                ++runid;
            }
        }
    }
    while (!q->empty()) {
        runs[runid].push_back(q->top());
        q->pop();
    }
    if (!wait->empty()) {
        runs.push_back(vector<int>());
        ++runid;
        while (!wait->empty()) {
            runs[runid].push_back(wait->top());
            wait->pop();
        }
    }
    vector<int> &run = runs[0];
    if (run.size() != 0) {
        printf("%d", run[0]);
        for (int i = 1; i < run.size(); ++i) printf(" %d", run[i]);
    }
    for (int r = 1; r < runs.size(); ++r) {
        vector<int> &run = runs[r];
        printf("\n");
        if (run.size() != 0) {
            printf("%d", run[0]);
            for (int i = 1; i < run.size(); ++i) printf(" %d", run[i]);
        }
    }

    return 0;
}
