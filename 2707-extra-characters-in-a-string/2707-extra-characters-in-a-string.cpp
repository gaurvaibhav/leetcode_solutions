class Solution {
public:
    int solve(int ind, int n, string& s, unordered_map<string, int>& mp, vector<int>& dp) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        string str = "";
        int res = n;
        for(int i=ind; i<n; ++i) {
            str += s[i];
            int cnt = 0;
            if(!mp[str]) {
                cnt=str.length();
            }
            int ncnt = solve(i+1, n, s, mp,dp);
            int curr = cnt + ncnt;
            res = min(res, curr);
        }
        return dp[ind] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        vector<int> dp(s.length()+1,-1);
        for(string& it: dictionary) {
            mp[it]++;
        }
        return solve(0, s.length(), s, mp,dp);
    }
};