#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
    int dfs(vector<vector<int>> &grid, int r, int c, int z, int n, int m)
    {
        FASTIO;
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == -1)
            return 0;
        if (grid[r][c] == 2)
        {
            return (z == -1);
        }
        grid[r][c] = -1;
        z--;
        int res = dfs(grid, r + 1, c, z, n, m) + dfs(grid, r - 1, c, z, n, m) + dfs(grid, r, c + 1, z, n, m) + dfs(grid, r, c - 1, z, n, m);
        grid[r][c] = 0;
        z++;
        return res;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        FASTIO;
        int r, c, z = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 0)
                    z++;
                if (grid[i][j] == 1)
                    r = i, c = j;
            }
        }
        return dfs(grid, r, c, z, n, m);
    }
};