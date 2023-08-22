#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    int solve(int n, vector<int>& dp) {
        op;
        dp[0]=0;
        for(int i=1; i<=n; i++) {
            int t,th;
            t=th=1e5;
            if(i-2>=0) t=min(t, 1+dp[i-2]);
            if(i-3>=0) th=min(th, 1+dp[i-3]);
            dp[i]=min(t,th);
        }
        return dp[n];
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