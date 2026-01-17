#include <iostream>
using namespace std;

int main() {
    int n , m;
    cin>>n>>m;
    int adj[n+1][n+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j] << " ";
        }
        cout << endl;
    }
}
