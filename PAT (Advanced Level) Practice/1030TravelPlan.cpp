#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, dist, cost;
    friend bool operator<(const Edge &e, const Edge &f) {
        return /* e.dist == f.dist ? e.cost > f.cost : */ e.dist > f.dist;
    }
};

int main(int argc, char const *argv[]) {
    int N, M, S, D;
    cin >> N >> M >> S >> D;

    vector<vector<Edge>> edgesFrom(N, vector<Edge>());
    int c1, c2, d, c;
    for (int i = 0; i < M; ++i) {
        cin >> c1 >> c2 >> d >> c;
        edgesFrom[c1].push_back({c2, d, c});
        edgesFrom[c2].push_back({c1, d, c});
    }

    // dijkstra
    const int INF = 0x4fffffff;
    vector<bool> visited(N, false);
    vector<int> dist(N, INF);
    vector<int> cost(N, INF);
    vector<int> pre(N, -1);
    priority_queue<Edge> pq;
    pq.push({S, 0, 0});
    dist[S] = 0;
    cost[S] = 0;
    while (!pq.empty()) {
        int fr = pq.top().to;
        pq.pop();
        if (!visited[fr]) {
            visited[fr] = true;
            for (Edge &e : edgesFrom[fr]) {
                if (!visited[e.to]) {
                    if (dist[fr] + e.dist < dist[e.to]) {
                        dist[e.to] = dist[fr] + e.dist;
                        cost[e.to] = cost[fr] + e.cost;
                        pre[e.to] = fr;
                        pq.push({e.to, dist[e.to], cost[e.to]});
                    } else if (dist[fr] + e.dist == dist[e.to] &&
                               cost[fr] + e.cost < cost[e.to]) {
                        cost[e.to] = cost[fr] + e.cost;
                        pre[e.to] = fr;
                        // pq.push({e.to, dist[e.to], cost[e.to]});
                    }
                }
            }
        } else if (fr == D)
            break;
    }
    vector<int> ans = {D};
    int v = D;
    while (pre[v] != S) {
        v = pre[v];
        ans.push_back(v);
    }

    cout << S << ' ';
    for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend();
         it++)
        cout << *it << ' ';
    cout << dist[D] << ' ' << cost[D];

    return 0;
}
