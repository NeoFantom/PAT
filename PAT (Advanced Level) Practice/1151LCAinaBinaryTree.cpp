#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

int M, N;
int preorder[10005];
int inorder[10005];
unordered_map<int, int> parent; // Can't assume the keys are 1~N

void makeTreeIn(int par, int *pre, int *in, int len) {
    if (len > 0) {
        int root = pre[0];
        parent[root] = par;

        int lsize = -1;
        while (in[++lsize] != root)
            ;
        int rsize = len - lsize - 1;
        makeTreeIn(root, pre + 1, in, lsize++);
        makeTreeIn(root, pre + lsize, in + lsize, len - lsize);
    }
}

void lca(int u, int v) {
    // if ((u < 1 || u > N) && (v < 1 || v > N))
    if (parent[u] == 0 && parent[v] == 0)
        printf("ERROR: %d and %d are not found.\n", u, v);
    // else if (u < 1 || u > N)
    else if (parent[u] == 0)
        printf("ERROR: %d is not found.\n", u);
    // else if (v < 1 || v > N)
    else if (parent[v] == 0)
        printf("ERROR: %d is not found.\n", v);
    else {
        stack<int> uanc, vanc;
        int p = u;
        while (p != -1) {
            uanc.push(p);
            p = parent[p];
        }
        p = v;
        while (p != -1) {
            vanc.push(p);
            p = parent[p];
        }
        int ans;
        while (!uanc.empty() && !vanc.empty()) {
            if (uanc.top() == vanc.top()) {
                ans = uanc.top();
                uanc.pop();
                vanc.pop();
            } else {
                break;
            }
        }
        if (ans == u)
            printf("%d is an ancestor of %d.\n", u, v);
        else if (ans == v)
            printf("%d is an ancestor of %d.\n", v, u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, ans);
    }
}

int main(int argc, char const *argv[]) {
    cin >> M >> N;
    for (int i = 0; i < N; ++i) cin >> inorder[i];
    for (int i = 0; i < N; ++i) cin >> preorder[i];
    makeTreeIn(-1, preorder, inorder, N);

    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        lca(u, v);
    }
    return 0;
}
