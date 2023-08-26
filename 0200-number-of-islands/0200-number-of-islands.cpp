#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    void bfsTraversal(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& arr,vector<pair<int,int>>& dir) {
        FASTIO;
        int n = arr.size();
        int m = arr[0].size();
        vis[r][c] = 1;
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()) {
            auto aux = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                int nr = aux.first + dir[i].first;
                int nc = aux.second + dir[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && arr[nr][nc]=='1') {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        FASTIO;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int cnt = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    ++cnt;
                    bfsTraversal(i,j,vis,grid,dir);
                }
            }
        }
        return cnt;
    }
};