//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int n, int m,int row, int col, vector<vector<int>>& arr, vector<vector<int>>& image, int p,vector<pair<int,int>>& dir, int clr) {
        arr[row][col] = p;
        for(int i=0; i<4; ++i) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==clr && arr[nr][nc]!=p ){
                dfs(n,m,nr,nc,arr,image,p,dir,clr);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int p) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> arr = image;
        int clr = arr[x][y];
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        dfs(n,m,x,y,arr,image,p,dir,clr);
        return arr;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends