class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n, total, mask, i, val, dist, newMask;
        n = graph.size();
        total = (1 << n) - 1;
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> vis;
        for (i = 0; i < n; ++i)
        {
            mask = (1 << i);
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            val = node.first;
            dist = node.second.first;
            mask = node.second.second;
            for (auto &it : graph[val])
            {
                newMask = mask | (1 << it);
                if (newMask == total)
                    return dist + 1;
                else if (vis.count({it, newMask}))
                    continue;
                else
                {
                    q.push({it, {dist + 1, newMask}});
                    vis.insert({it, newMask});
                }
            }
        }
        return 0;
    }
};