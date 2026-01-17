#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newRow = r + dr[k];
                int newCol = c + dc[k];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;                 // example: "11001"
        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j];
        }
    }

    Solution sol;
    cout << sol.numIslands(grid) << "\n";

    return 0;
}
