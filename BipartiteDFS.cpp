#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
    color[node] = col;

    for (int neigh : adj[node]) {
        if (color[neigh] == -1) {
            if (!dfs(neigh, 1 - col, color, adj)) return false;
        } 
        else if (color[neigh] == color[node]) {
            return false;
        }
    }

    return true;
}

bool isBipartiteDFS(int n, vector<vector<int>>& adj) {
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0, color, adj)) return false;
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

    cout << (isBipartiteDFS(n, adj) ? "true" : "false") << "\n";
    return 0;
}
