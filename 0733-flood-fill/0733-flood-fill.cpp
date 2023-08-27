#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    void dfs(int n, int m,int row, int col, vector<vector<int>>& arr, vector<vector<int>>& image, int p,vector<pair<int,int>>& dir, int clr) {
        FASTIO;
        arr[row][col] = p;
        for(int i=0; i<4; ++i) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==clr && arr[nr][nc]!=p ){
                dfs(n,m,nr,nc,arr,image,p,dir,clr);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        FASTIO;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> arr = image;
        int clr = arr[sr][sc];
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        dfs(n,m,sr,sc,arr,image,newColor,dir,clr);
        return arr;
    }
};