#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    bool solve(string& s, vector<string>& w, int ind, vector<int>& dp) {
        op;op;
        if(ind == s.length()) return true;
        if(dp[ind] != -1) return dp[ind];
        bool ans = false;
        for(int i=0; i<w.size(); ++i) {
            if(w[i] == s.substr(ind,w[i].size())) {
                ans = ans || solve(s,w,ind+w[i].size(),dp);
            }
        }
        return dp[ind] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        op;op;
        vector<int> dp(s.size(),-1);
        return solve(s,wordDict,0,dp);
    }
};