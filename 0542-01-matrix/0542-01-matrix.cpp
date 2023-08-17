#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        op;
        int m = mat.size(), n = mat[0].size();
        vector<int> directions = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col)
                if (mat[row][col] == 0) q.push({row, col});
                else mat[row][col] = -1;
        while (!q.empty()) {
            int row = (q.front()).first;
            int col = (q.front()).second;
            q.pop();
            for (int i = 0; i <= 3; ++i) {
                int trows = row + directions[i], tcolumns = col + directions[i+1];
                if (trows < 0 || trows == m || tcolumns < 0 || tcolumns == n || mat[trows][tcolumns] != -1) continue;
                mat[trows][tcolumns] = mat[row][col] + 1;
                q.emplace(trows, tcolumns);
            }
        }
        return mat;
    }
};
