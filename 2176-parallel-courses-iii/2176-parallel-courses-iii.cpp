#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
    {
        FASTIO;
        int i, f;
        vector<int> inDegree(n), dist(n);
        queue<int> q;
        vector<vector<int>> adj(n, vector<int>());
        for(auto& relation: relations)
        {
            int u = relation[0] - 1, v = relation[1] - 1;
            adj[u].push_back(v);
            inDegree[v]++;
        }
        for(i=0; i<n; ++i)
        {
            if(!inDegree[i])
            {
                q.push(i);
                dist[i] = time[i];
            }
        }
        while(!q.empty())
        {
            f = q.front();
            q.pop();
            for(int& e : adj[f])
            {
                dist[e] = max(dist[e], dist[f] + time[e]);
                inDegree[e]--;
                if(!inDegree[e]) q.push(e);
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};