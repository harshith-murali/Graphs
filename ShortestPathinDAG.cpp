#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    void topoDFS(int node, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto &it : adj[node]) {
            int v = it.first;
            if (!vis[v]) topoDFS(v, adj, vis, st);
        }
        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges, int src) {
        vector<pair<int,int>> adj[N];
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
        }

        // Topological sort
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) topoDFS(i, adj, vis, st);
        }

        // Distance array
        const int INF = 1e9;
        vector<int> dist(N, INF);
        dist[src] = 0;

        // Relax in topo order
        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (dist[u] == INF) continue;

            for (auto &it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // If you want unreachable as -1:
        for (int i = 0; i < N; i++) {
            if (dist[i] == INF) dist[i] = -1;
        }

        return dist;
    }
};

int main() {
    Solution sol;

    // Example DAG
    int N = 6, M = 7;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {4, 5, 4},
        {2, 3, 6},
        {5, 3, 1}
    };

    int src = 0;
    vector<int> dist = sol.shortestPath(N, M, edges, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << " -> " << dist[i] << "\n";
    }

    return 0;
}
