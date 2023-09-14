#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        FASTIO;
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; ++i) {
            if(!leftRow[i] && !upperDiagonal[n-1+col-i] && !lowerDiagonal[i+col]) {
                board[i][col] = 'Q';
                leftRow[i] = 1;
                upperDiagonal[n-1+col-i] = 1;
                lowerDiagonal[i+col] = 1;
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[i][col] = '.';
                leftRow[i] = 0;
                upperDiagonal[n-1+col-i] = 0;
                lowerDiagonal[i+col] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        FASTIO;
        vector<vector<string>> res;
        vector<string> board;
        string s(n, '.');
        for(int i=0; i<n; ++i) {
            board.push_back(s);
        }
        vector<int> leftRow(n,0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        solve(0, board, res, leftRow, upperDiagonal, lowerDiagonal, n);
        return res.size();
    }
};