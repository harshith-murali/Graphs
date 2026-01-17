#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(int V, vector<vector<int>> &adj){
    vector<int> ans;
    vector<int> vis(V,0);
    queue<int> q;

    for(int i=0; i<V; i++){
        if(!vis[i]){
            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfsTraversal = bfs(n, adj);

    for(auto node : bfsTraversal){
        cout << node << " ";
    }
}
