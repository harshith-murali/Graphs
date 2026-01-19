#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detectCycle(int src , vector<vector<int>> &adj , vector<int> & vis){
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]  = 1;
                q.push({it , node});
            }else if(parent != it){
                return true;
            }
        }

    }
    return false;

}

int main(){
    vector<vector<int>> adj;
    int n , m;
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n , 0);
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            if(detectCycle(i , adj , vis)){
                cout << "Cycle Detected" << endl;
                return 0;
            }
        }
    }
    cout << "No Cycle Detected" << endl;
    return 0;
}