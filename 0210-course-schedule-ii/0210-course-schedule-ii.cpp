#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    vector<int> findOrder(int nodes, vector<vector<int>>& arr) {
        op;
        vector<vector<int>> adj(nodes);
        for (auto& it: arr) adj[it[1]].push_back(it[0]);
        vector<int> indegree(nodes, 0);
        for (int i = 0; i < nodes; ++i)
        {
            for (auto &it : adj[i]) indegree[it]++;
        }
        queue<int> q;
        for (int i = 0; i < nodes; ++i)
        {
            if (!indegree[i])
                q.push(i);
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto &it : adj[node])
            {
                indegree[it]--;
                if (!indegree[it]) q.push(it);
            }
        }
        if(topo.size() == nodes) return topo; 
        return {};
    }
};