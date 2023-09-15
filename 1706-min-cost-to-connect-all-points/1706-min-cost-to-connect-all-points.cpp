#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    int find(int a, vector<int>& parent) {
        FASTIO;
        if(parent[a] < 0) return a;
        return parent[a] = find(parent[a], parent);
    }
    void Union(int a, int b, vector<int>& parent) {
        FASTIO;
        parent[a] = b;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        FASTIO;
        int n = points.size();
        vector<int> parent(n);
        for(int i=0; i<n; ++i) {
            parent[i] = -1;
        }
        vector<pair<int, pair<int, int>>> adj;
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); 
                adj.push_back({weight, {i, j}});
            }
        }
        sort(adj.begin(), adj.end());
        int sum = 0;
        for(int i=0; i<adj.size(); ++i) {
            int a = find(adj[i].second.first, parent);
            int b = find(adj[i].second.second, parent);
            if(a != b) {
                sum += adj[i].first;
                Union(a, b, parent);
            }
        }
        return sum;
    }
};