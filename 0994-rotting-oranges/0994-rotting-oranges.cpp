#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        FASTIO;
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> vis(n, vector<int> (m,0));
        queue< pair< pair< int, int >,int > > q;
        int cfresh = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) cfresh++;
            }
        }
        int tm=0;
        int cnt = 0;
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for(int i=0; i<4; ++i) {
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                    q.push({{nr,nc}, t+1});
                    vis[nr][nc] = 2;
                    ++cnt;
                }
            }
        }
        if(cnt != cfresh) return -1;
        return tm;
    }
};