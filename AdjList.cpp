#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> lis(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        lis[u].push_back({v, w});
        lis[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto it : lis[i])
        {
            cout << "(" << it.first << "," << it.second << ")";
        }
        cout << endl;
    }
}