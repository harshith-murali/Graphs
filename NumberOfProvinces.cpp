#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>> &matrix, vector<int> &vis) {
        vis[node] = 1;
        for (int it : matrix[node]) {
            if (!vis[it]) {
                dfs(it, matrix, vis);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        int n = adj.size();

        // Convert adjacency matrix -> adjacency list
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1 && i != j) {
                    matrix[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, matrix, vis);
            }
        }
        return provinces;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adj[i][j];
        }
    }

    Solution obj;
    cout << obj.numProvinces(adj, V) << "\n";

    return 0;
}
