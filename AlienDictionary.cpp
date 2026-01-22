#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        int N = (int)words.size();

        // 1) Collect all unique characters (sorted for deterministic mapping)
        vector<int> present(256, 0);
        for (auto &w : words) {
            for (char c : w) present[(unsigned char)c] = 1;
        }

        vector<char> chars;
        for (int i = 0; i < 256; i++) {
            if (present[i]) chars.push_back((char)i);
        }

        int K = (int)chars.size();

        // Map char -> index
        vector<int> mp(256, -1);
        for (int i = 0; i < K; i++) mp[(unsigned char)chars[i]] = i;

        // 2) Build graph (avoid duplicate edges)
        vector<unordered_set<int>> adj(K);
        vector<int> indegree(K, 0);

        for (int i = 0; i < N - 1; i++) {
            string &s1 = words[i];
            string &s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            int j = 0;

            while (j < len && s1[j] == s2[j]) j++;

            // Prefix invalid case: "abcd" before "ab"
            if (j == len && s1.size() > s2.size()) {
                return "";
            }

            // First mismatch gives ordering constraint
            if (j < len) {
                int u = mp[(unsigned char)s1[j]];
                int v = mp[(unsigned char)s2[j]];

                // Insert edge only once
                if (adj[u].insert(v).second) {
                    indegree[v]++;
                }
            }
        }

        // 3) Topological Sort (Kahn BFS)
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        string ans = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(chars[node]);

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }

        // 4) Cycle check
        if ((int)ans.size() != K) return "";
        return ans;
    }
};

// --------------------- MAIN (VS Code Testing) ---------------------
int main() {
    Solution sol;

    // Example:
    // Input words sorted in alien language
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    string order = sol.findOrder(words);

    if (order == "") {
        cout << "Invalid dictionary (cycle/prefix issue)\n";
    } else {
        cout << "Alien order: " << order << "\n";
    }

    return 0;
}
