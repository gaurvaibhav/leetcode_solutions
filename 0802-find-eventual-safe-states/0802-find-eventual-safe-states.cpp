class Solution {
private:
    bool dfsChk(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis, vector<int>& check){
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
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int v = adj.size();
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