#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis(V + 1, 0);
    queue<int> q;

    for (int start = 1; start <= V; start++) {
        if (!vis[start]) {
            q.push(start);
            vis[start] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (int it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res = bfs(n, adj);
    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}
