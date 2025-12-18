#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;   // n = nodes, m = edges

    int adj[n+1][n+1];

    // Initialize matrix with 0
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // because undirected
    }

    // Print adjacency matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
