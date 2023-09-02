#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    bool canFinish(int nodes, vector<vector<int>> &arr)
    {
        op;
        vector<vector<int>> adj(nodes);
        for (auto& it: arr)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indegree(nodes, 0);
        for (int i = 0; i < nodes; ++i)
        {
            for (auto &it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < nodes; ++i)
        {
            if (!indegree[i])
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto &it : adj[node])
            {
                indegree[it]--;
                if (!indegree[it])
                    q.push(it);
            }
        }
        return cnt == nodes;
    }
};