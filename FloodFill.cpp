#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &image, int oldColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // boundary + color check
        if (r < 0 || c < 0 || r >= n || c >= m)
            return;

        if (image[r][c] != oldColor)
            return;

        // fill color
        image[r][c] = newColor;

        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            dfs(r + rows[k], c + cols[k], image, oldColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];

        // edge case: same color
        if (oldColor == newColor)
            return image;

        dfs(sr, sc, image, oldColor, newColor);
        return image;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;

    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
