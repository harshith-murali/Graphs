#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adjRev(n);
        vector<int> outdegree(n, 0);

        // Build reverse graph + outdegree array
        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();
            for (int v : graph[u]) {
                adjRev[v].push_back(u);
            }
        }

        // Push terminal nodes (outdegree == 0)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for (int parent : adjRev[node]) {
                outdegree[parent]--;
                if (outdegree[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};

int main() {
    Solution sol;

    // Example graph:
    // graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> ans = sol.eventualSafeNodes(graph);

    cout << "Safe Nodes: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
