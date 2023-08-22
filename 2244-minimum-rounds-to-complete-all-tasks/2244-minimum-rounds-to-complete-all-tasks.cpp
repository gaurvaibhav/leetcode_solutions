#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    int solve(int n, vector<int>& dp) {
        op;
        if(!n) return 0;
        if(dp[n]!=-1) return dp[n];
        int t,th;
        t = th = 1e6;
        if(n-2>=0) t = min(t, 1+solve(n-2,dp));
        if(n-3>=0) th = min(th, 1+solve(n-3,dp));
        return dp[n] = min(t,th);        
    }
public:
    int minimumRounds(vector<int>& tasks) {
        op;
        unordered_map<int, int> mp;
        vector<int> dp(tasks.size()+1,-1);
        for(int task: tasks)
            mp[task]++;
        int res=0;
        for(auto it: mp) {
            int ans = solve(it.second,dp);
            if(ans >= 1e5) return -1;
            res += ans;
        }
        return res;
    }
};