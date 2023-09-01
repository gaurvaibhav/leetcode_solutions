//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfsChk(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathvis, vector<int>& check){
    	vis[node] = 1;
    	pathvis[node] = 1;
    	check[node] = 0;
    	for(auto& it: adj[node]) {
    		if(!vis[it]) {
    			if(dfsChk(it, adj, vis, pathvis, check))  return true;

    		}
    		else if(pathvis[it]) 
    		    return true;
    	}
    	check[node] = 1;
    	pathvis[node] = 0;
    	return false;
    }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> vis(v, 0), pathvis(v, 0), check(v,0), safeNodes;
    	for(int i=0; i<v; ++i ) {
    		if(!vis[i]) {
    		    dfsChk(i, adj, vis, pathvis, check);
    		}
    	}
    	for(int i=0; i<v; ++i) {
    	        if(check[i] == 1) safeNodes.push_back(i);
    	}
    	return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends