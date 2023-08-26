#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    vector<int> bfsTraversal(int V, vector<vector<int>>& adj, int node, vector<int>& vis) {
        vector<int> res;
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int aux = q.front();
            q.pop();
            res.push_back(aux);
            for(int it: adj[aux]) {
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }

        }
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
                res.push_back(bfsTraversal(n, adj, i,vis));
            }
        }
        return ans;
    }
};