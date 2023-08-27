//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool detect(int node, int parent, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(detect(it, node, adj, vis)) return true;
            }
            else if(parent != it) {
                return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        // Write your code here.
        vector<int> vis(V,0);
        for(int i=0; i<V; ++i) {
            // checking all the components of the graph (disconnected if any)
            if(!vis[i]) {
                if(detect(i,-1,adj,vis)) return true;
            }
        } 
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends