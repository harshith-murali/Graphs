#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // min heap: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // stale entry skip
        if (dis > dist[node]) continue;

        for (auto &it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {
    int V = 5; // number of vertices (0 to V-1)

    vector<vector<pair<int,int>>> adj(V);

    // add edges: u -> v (weight)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int src = 0;

    vector<int> dist = dijkstra(V, adj, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << dist[i] << "\n";
    }

    return 0;
}
