#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    void dfs(int r, int c, int n, int m, vector<vector<int>>& arr, vector<vector<int>>& vis, vector<pair<int,int>>& dir) {
        FASTIO;
        vis[r][c] = 1;
        for(int i=0; i<4; ++i) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if(nr>=0 && nr<n && nc>=0 && nc<m && arr[nr][nc]==1 && !vis[nr][nc])
            dfs(nr,nc,n,m,arr,vis,dir);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        FASTIO;
        int n = grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0; i<n; ++i) {
            if(grid[i][0]==1) 
                dfs(i,0,n,m,grid,vis,dir);
            if(grid[i][m-1]==1) 
                dfs(i,m-1,n,m,grid,vis,dir);
        }
        for(int i=0; i<m; ++i) {
            if(grid[0][i]==1) 
                dfs(0,i,n,m,grid,vis,dir);
            if(grid[n-1][i]==1) 
                dfs(n-1,i,n,m,grid,vis,dir);
        }
        int res = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]==1 && !vis[i][j]) res++; 
            }
        } 
        return res;
    }
};