#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int area = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + delrow[k];
                int nc = c + delcol[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !vis[nr][nc] && grid[nr][nc] == 1) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                    area++;
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    ans = max(ans, bfs(i, j, vis, grid));
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 0, 1}
    };

    Solution sol;
    cout << "Max Area of Island (BFS): " << sol.maxAreaOfIsland(grid) << "\n";
    return 0;
}
