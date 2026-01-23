#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        // 1) Build adjacency list
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // 2) Dijkstra using set
        vector<long long> dist(n + 1, (long long)1e18);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        set<pair<long long,int>> st; // {dist, node}
        dist[1] = 0;
        st.insert({0, 1});

        while (!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());

            long long dis = top.first;
            int node = top.second;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (dis + wt < dist[adjNode]) {
                    // remove old entry if it exists
                    if (dist[adjNode] != (long long)1e18) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + wt;
                    parent[adjNode] = node;

                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        // 3) If unreachable
        if (dist[n] == (long long)1e18) return {-1};

        // 4) Reconstruct path 1 -> n
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        // 5) Return [distance, path...]
        vector<int> ans;
        ans.push_back((int)dist[n]);
        for (int x : path) ans.push_back(x);

        return ans;
    }
};

int main() {
    Solution sol;

    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };

    vector<int> res = sol.shortestPath(n, m, edges);

    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}
