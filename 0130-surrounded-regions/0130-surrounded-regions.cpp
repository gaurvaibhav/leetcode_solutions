#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    void markAdj(int r, int c, int n, int m, vector<vector<char>>& arr, vector<vector<int>>& vis, vector<pair<int, int>>& dir) {
        FASTIO;
        vis[r][c] = 1;
        for(int i=0; i<4; ++i) {
            int nr = r+dir[i].first;
            int nc = c+dir[i].second;
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && arr[nr][nc] == 'O') {
                markAdj(nr, nc, n, m, arr, vis, dir);
                
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        FASTIO;
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<pair<int, int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0; i<n; ++i) {
            if(!vis[i][0] && board[i][0] == 'O') {
                markAdj(i,0,n,m,board,vis,dir);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                markAdj(i,m-1,n,m,board,vis,dir);
            }
        }
        for(int i=0; i<m; ++i) {
            if(!vis[0][i] && board[0][i] == 'O') {
                markAdj(0,i,n,m,board,vis,dir);
            }
            if(!vis[n-1][i] && board[n-1][i] == 'O') {
                markAdj(n-1,i,n,m,board,vis,dir);
            }
        }
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }   
            }
        }
    }
};