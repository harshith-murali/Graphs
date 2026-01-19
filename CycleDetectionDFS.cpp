#include<iostream>
#include<vector>
using namespace std;

bool detectCycle(int node, int parent , vector<vector<int>> && adj , vector<int> & vis){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(detectCycle(it , node , move(adj) , vis))
                return true;
        }
        else if(parent != it){
            return true;
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
            if(detectCycle(i , -1 , move(adj) , vis)){
                cout << "Cycle Detected" << endl;
                return 0;
            }
        }
    }
    cout << "No Cycle Detected" << endl;
    return 0;
}