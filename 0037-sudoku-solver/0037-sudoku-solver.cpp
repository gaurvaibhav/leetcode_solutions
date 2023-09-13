#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
  bool chk(vector<vector<char>>& board, int r, int c, char s) {
    FASTIO;
    for(int i=0; i<9; ++i) {
      if(board[i][c] == s || board[r][i] == s) return false;
      if(board[3*(r/3)+i/3][3*(c/3)+i%3] == s) return false;
    }
    return true;
  }
  bool solve(vector<vector<char>>& board) {
    FASTIO;
    for(int i=0; i<9; ++i) {
      for(int j=0; j<9; ++j) {
        if(board[i][j] == '.') {
          for(char c = '1'; c <= '9'; ++c) {
            if(chk(board, i, j, c)) {
              board[i][j] = c;
              if(solve(board)) return true;
              else board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    FASTIO;
      solve(board);
  }
};