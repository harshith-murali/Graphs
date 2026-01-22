#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(V, (int)1e9);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node]) {
                if (dist[node] + 1 < dist[nbr]) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == (int)1e9) dist[i] = -1;
        }

        return dist;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;
    edges.reserve(E);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int src;
    cin >> src;

    Solution sol;
    vector<int> ans = sol.shortestPath(V, edges, src);

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
