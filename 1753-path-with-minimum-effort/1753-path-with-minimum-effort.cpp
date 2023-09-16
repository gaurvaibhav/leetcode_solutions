class Solution {
public:
    int dikstra(vector<vector<int>>& a, vector<vector<int>>& res)
    {
        int n=a.size(), m=a[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        res[0][0] = 0;
        while(!pq.empty())
        {
            int i = pq.top()[0];
            int j = pq.top()[1];
            int w = pq.top()[2];
            pq.pop();
            
            if(i>0 && res[i-1][j]>max(w,abs(a[i][j]-a[i-1][j])) )
            {
                res[i-1][j] = max(w,abs(a[i][j]-a[i-1][j]));
                pq.push({i-1,j,res[i-1][j]});
            }
            if(i<n-1 && res[i+1][j]>max(w,abs(a[i][j]-a[i+1][j])) )
            {
                res[i+1][j] = max(w,abs(a[i][j]-a[i+1][j]));
                pq.push({i+1,j,res[i+1][j]});
            }
            if(j>0 && res[i][j-1]>max(w,abs(a[i][j]-a[i][j-1])) )
            {
                res[i][j-1] = max(w,abs(a[i][j]-a[i][j-1]));
                pq.push({i,j-1,res[i][j-1]});
            }
            if(j<m-1 && res[i][j+1]>max(w,abs(a[i][j]-a[i][j+1])) )
            {
                res[i][j+1] = max(w,abs(a[i][j]-a[i][j+1]));
                pq.push({i,j+1,res[i][j+1]});
            }
        }
        
        return res[n-1][m-1];
    }
    
    int minimumEffortPath(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<vector<int>> res(n, vector<int>(m,INT_MAX));
        int ans = dikstra(a,res);
        return ans;
    }
};