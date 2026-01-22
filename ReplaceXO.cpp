#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int r, int c, vector<vector<char>> &board, vector<vector<char>> &vis)
    {
        vis[r][c] = 1;

        int n = board.size();
        int m = board[0].size();

        int delrow[4] = {-1, 0, +1, 0};
        int delcol[4] = {0, +1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> vis(n, vector<char>(m, 0));

        // Check boundary rows
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, board, vis);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, board, vis);
        }

        // Check boundary cols
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, board, vis);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, board, vis);
        }

        // Convert all unvisited 'O' -> 'X'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// Helper function to print the board
void printBoard(const vector<vector<char>> &board)
{
    for (auto &row : board)
    {
        for (auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    cout << "Before solve():\n";
    printBoard(board);

    Solution obj;
    obj.solve(board);

    cout << "\nAfter solve():\n";
    printBoard(board);

    return 0;
}
