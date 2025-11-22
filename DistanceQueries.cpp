#include <bits/stdc++.h>
using namespace std;

static const int LOG = 20;  // supports up to 2^20 ˜ 1e6 nodes

vector<vector<int>> tree;
vector<int> depth;
vector<array<int, LOG>> up;

void dfs(int root) {
    stack<int> st;
    st.push(root);
    up[root][0] = 1;   // parent of root is itself
    depth[root] = 0;

    vector<bool> vis(tree.size(), false);
    vis[root] = true;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v : tree[u]) {
            if (!vis[v]) {
                vis[v] = true;
                depth[v] = depth[u] + 1;
                up[v][0] = u;

                for (int j = 1; j < LOG; j++)
                    up[v][j] = up[ up[v][j-1] ][j-1];

                st.push(v);
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a,b);

    int diff = depth[a] - depth[b];
    for (int j = 0; j < LOG; j++)
        if (diff & (1 << j))
            a = up[a][j];

    if (a == b) return a;

    for (int j = LOG-1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    tree.assign(n+1, {});
    depth.assign(n+1, 0);
    up.assign(n+1, {});

    // read tree
    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // preprocess
    dfs(1);

    // answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;

        int c = lca(a,b);
        int dist = depth[a] + depth[b] - 2 * depth[c];

        cout << dist << "\n";
    }

    return 0;
}

