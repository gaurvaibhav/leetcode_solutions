#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
  void dfs(unordered_map<string, multiset<string>>& adj, vector<string>& res, string src) {
    FASTIO;
    while(adj[src].size()) {
      string aux = *(adj[src].begin());
      adj[src].erase(adj[src].begin());
      dfs(adj, res, aux);
    }
    res.push_back(src);
  }
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    FASTIO;
    unordered_map<string, multiset<string>> adj;
    for(auto& it: tickets) {
      adj[it[0]].insert(it[1]);
    }
    vector<string> res;
    dfs(adj, res, "JFK");
    reverse(res.begin(), res.end());
    return res;
  }
};