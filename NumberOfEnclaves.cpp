#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vis[r][c] = 1;
        q.push({r, c});

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // boundary rows
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && grid[0][j] == 1)
                bfs(0, j, vis, grid);
            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
                bfs(n - 1, j, vis, grid);
        }

        // boundary cols
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && grid[i][0] == 1)
                bfs(i, 0, vis, grid);
            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
                bfs(i, m - 1, vis, grid);
        }

        int countEnclaves = 0;

        // count unvisited land (enclaves)
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    countEnclaves++;
                }
            }
        }

        return countEnclaves;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.numEnclaves(grid) << "\n";

    return 0;
}
