#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct Edge {
    int fromid;
    int toid;
    Edge(int f, int t) : fromid(f), toid(t) {}
};

vector<Edge> edges;

int N, R, K, M;

bool planYes(vector<int> plan) {
    for (Edge &e : edges)
        if (plan[e.fromid - 1] == plan[e.toid - 1]) return false;
    return true;
}

void judgePlan(vector<int> plan) {
    unordered_set<int> s;
    for (int i : plan) s.insert(i);

    if (s.size() > K)
        printf("Error: Too many species.");
    else if (s.size() < K)
        printf("Error: Too few species.");
    else if (planYes(plan))
        printf("Yes");
    else
        printf("No");
}

int main(int argc, char const *argv[]) {
    scanf("%d %d %d", &N, &R, &K);

    for (int i = 0; i < R; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges.push_back(Edge(from, to));
    }

    scanf("%d", &M);

    vector<vector<int>> plans(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j) scanf("%d", &(plans[i][j]));

    for (int i = 0; i < M - 1; ++i) {
        judgePlan(plans[i]);
        printf("\n");
    }
    judgePlan(plans[M - 1]);

    return 0;
}