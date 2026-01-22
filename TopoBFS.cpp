#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TopoSortDFS {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis, st);
            }
        }

        // after exploring all neighbors
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};

int main() {
    int V, E;
    cout << "Enter number of nodes (V) and edges (E): ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges u v (meaning u -> v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    TopoSortDFS solver;
    vector<int> topo = solver.topoSort(V, adj);

    cout << "Topological Order (DFS): ";
    for (int x : topo) cout << x << " ";
    cout << "\n";

    return 0;
}
