class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<vector<int>> adjRev(v);
        vector<int> indegree(v,0);
        for(int i=0; i<v; ++i) {
            for(auto& it: adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<v; ++i) {
            if(!indegree[i]) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto& it: adjRev[node]) {
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};