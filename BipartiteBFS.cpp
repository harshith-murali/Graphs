#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartiteBFS(int n, vector<vector<int>>& adj) {
    vector<int> color(n, -1);

    for (int start = 0; start < n; start++) {
        if (color[start] != -1) continue;

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                if (color[neigh] == -1) {
                    color[neigh] = 1 - color[node];
                    q.push(neigh);
                } else if (color[neigh] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (isBipartiteBFS(n, adj) ? "true" : "false") << "\n";
    return 0;
}
