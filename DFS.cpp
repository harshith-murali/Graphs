#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfsUtil(int node, vector<vector<int>>& adj,
                 vector<int>& vis, vector<int>& ans) {
        vis[node] = 1;
        ans.push_back(node);

        for (int it : adj[node]) {
            if (!vis[it]) {
                dfsUtil(it, adj, vis, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(), 0);
        vector<int> ans;

        int start = 0;   // starting node
        dfsUtil(start, adj, vis, ans);

        return ans;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    Solution obj;
    vector<int> res = obj.dfs(adj);

    for (int node : res) {
        cout << node << " ";
    }

    return 0;
}
