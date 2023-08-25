#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    bool solve(string a, string b, string c, int i, int j, int k, vector<vector<int> >& dp) {
        FASTIO;
        if(i<0 && j<0 && k<0) return true;
        if(i>=0 && j>=0 && dp[i][j]!=-1) return dp[i][j];
        if(i>=0 && c[k] == a[i] && j>=0 && c[k] == b[j]) {
            return dp[i][j] = solve(a,b,c,i-1,j,k-1,dp) || solve(a,b,c,i,j-1,k-1,dp);
        }
        else if(i>=0 && c[k] == a[i]) {
            return solve(a,b,c,i-1,j,k-1,dp);
        }
        else if(j>=0 && c[k] == b[j]) {
            return solve(a,b,c,i,j-1,k-1,dp);
        }
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        FASTIO;
        int i,j,k;
        i = s1.length(); j = s2.length(); k=s3.length();
        if(k!=i+j) return false;
        vector<vector<int >> dp(i, vector<int > (j,-1));
        return solve(s1,s2,s3,i-1,j-1,k-1,dp);
    }
};