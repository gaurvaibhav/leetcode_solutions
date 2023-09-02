#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
private:
    bool dfsChk(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis)
    {
        op;
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto& it: adj[node]) {
            if(!vis[it]) {
                if(dfsChk(it, adj, vis, pathvis)) return  true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(vector<vector<int>>& adj, int v)
    {
        op;
        vector<int> vis(v, 0);
        vector<int> pathvis(v, 0);
        for(int i=0; i<v; ++i ) {
            if(!vis[i]) {
                if(dfsChk(i, adj, vis, pathvis)) return true;
            }
        }
        return false;
    }
public:
    bool canFinish(int nodes, vector<vector<int>> &arr)
    {
        op;
        vector<vector<int>> adj(nodes);
        for (auto& it: arr)
        {
            adj[it[0]].push_back(it[1]);
        }
        return !isCyclic(adj, nodes);
    }
};