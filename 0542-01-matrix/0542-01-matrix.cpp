#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    vector<vector<int>>updateMatrix (vector<vector<int>>& grid)
	{
        FASTIO;
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> vis(n,vector<int> (m,0)),dist(n,vector<int> (m,0));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0; i<n; ++i) {
	        for(int j=0; j<m; ++j) {
	            if(grid[i][j] == 0) {
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
	    while(!q.empty()) {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        dist[row][col] = steps;
	        for(int i=0; i<4; ++i) {
	            int nr = row + dir[i].first;
	            int nc = col + dir[i].second;
	            if(nr>=0 && nr<n && nc >=0 && nc<m && vis[nr][nc] == 0) {
	                vis[nr][nc] = 1;
	                q.push({{nr,nc},steps+1});
	            }
	        }
	    }
	    return dist;
	}
};