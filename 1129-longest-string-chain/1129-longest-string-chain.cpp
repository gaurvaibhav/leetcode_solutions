class Solution {
private:
    bool check(string& s1, string& s2) {
        int n, m, i, j;
        n = s1.size(), m = s2.size();
        if(n != m+1) return false;
        i = j = 0;
        while(i < n) {
            if(s1[i] == s2[j]) i++, j++;
            else i++;
        }
        return (i==n && j==m);
    }
    static bool comp(string& s1, string& s2) {
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& arr) {
        int n, maxi;
        n = arr.size();maxi = 1;
        sort(arr.begin(), arr.end(), comp);
        vector<int> dp(n, 1);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<=i-1; ++j) {
                if(check(arr[i], arr[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            if(dp[i] > maxi) maxi = dp[i];
        }
        return maxi;
    }
};