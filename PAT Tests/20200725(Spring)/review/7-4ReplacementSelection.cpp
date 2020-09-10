#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
priority_queue<int, vector<int>, greater<int> > Q, q;
vector<int> ans[maxn];
int n, m, a[maxn], tag = 1;

void solve() {
    int i, j;
    for (i = 1; i <= m; ++i) Q.push(a[i]);
    int cnt = m + 1;
    while (cnt <= n) {
        if (Q.empty()) {  //当前队列空
            while (!q.empty()) {
                Q.push(q.top());
                q.pop();
            }
            tag++;
        }
        if (Q.empty()) return;
        int e = Q.top();
        Q.pop();
        ans[tag].push_back(e);
        if (a[cnt] < e) {
            q.push(a[cnt]);
        } else {
            Q.push(a[cnt]);
        }
        ++cnt;
    }
    if (Q.empty()) {  //当前队列空
        while (!q.empty()) {
            Q.push(q.top());
            q.pop();
        }
        tag++;
    }
    while (!Q.empty()) {
        int e = Q.top();
        Q.pop();
        ans[tag].push_back(e);
    }
}

int main() {
    int t, i, j;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (i = 1; i <= n; ++i) cin >> a[i];
    solve();
    for (i = 1; i <= tag; ++i) {
        sort(ans[i].begin(), ans[i].end());
    }
    for (i = 1; i <= tag; ++i) {
        if (ans[i].empty()) continue;

        cout << ans[i][0];
        for (j = 1; j < ans[i].size(); ++j) {
            cout << ' ' << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}
