#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isValidCell(int row, int col, int N, int M) {
    return (row >= 0 && row < N && col >= 0 && col < M);
}

class Solution {
public:
    void dfs(int row, int col,
             vector<vector<int>>& vis,
             vector<vector<int>>& grid,
             vector<pair<int,int>>& shape,
             int baseRow, int baseCol) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        shape.push_back({row - baseRow, col - baseCol});

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (isValidCell(nrow, ncol, n, m) &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, vis, grid, shape, baseRow, baseCol);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> shape;
                    dfs(i, j, vis, grid, shape, i, j);
                    st.insert(shape);
                }
            }
        }

        return (int)st.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.countDistinctIslands(grid) << "\n";

    return 0;
}
