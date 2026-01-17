#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> &vis , vector<vector<int>> &adj , vector<int>& ans){
    vis[node] = 1;
    ans.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it , vis , adj , ans);
        }
    }
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

    vector<int> vis(n, 0);
    vector<int> ans;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i , vis , adj , ans);
        }
    }

    for(auto node : ans){
        cout << node << " ";
    }
}