#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    // adjacency matrix
    vector<vector<int>> adjMat(n, vector<int>(n,0));
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; // for undirected graph
    }

    //converting to adjacency list
    vector<vector<int>> adjList(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adjMat[i][j] == 1 && i != j){
                adjList[i].push_back(j);
            }
        }
    }
    //printing adjacency list
    for(int i=0; i<n; i++){
        cout << i << " -> ";
        for(auto node : adjList[i]){
            cout << node << " "; 
        }
        cout << endl;
    }
}