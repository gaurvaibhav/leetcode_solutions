#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
        FASTIO;
        vis[node] = 1;
        ans.push_back(node);
        for(int it: adj[node]) {
            if(!vis[it]){
                dfs(it,adj,vis,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj, int node, vector<int>& vis) {
        FASTIO;
        vector<int> res;
        dfs(node,adj,vis,res);
        return res;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        FASTIO;
        int n = isConnected.size();
        int ans = 0;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n),res;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(isConnected[i][j]==1) {
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                ans++;
                res.push_back(dfsOfGraph(n, adj, i,vis));
            }
        }
        return ans;
    }
};