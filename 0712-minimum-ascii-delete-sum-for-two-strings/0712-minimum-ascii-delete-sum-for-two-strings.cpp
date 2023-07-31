#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    int helper(string s1,string s2) {
        op;op;
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
          for(int i=n-1;i>=0;i--){
              for(int j=m-1;j>=0;j--){
                  int ans=0;
                  if(s1[i]==s2[j]){
                      ans=s1[i]+dp[i+1][j+1];
                  }else{
                      ans=max(dp[i+1][j],dp[i][j+1]);
                  }
                  dp[i][j]=ans;
              }
          }
          return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        op;op;
        int n=s1.length(),m=s2.length();
        int totalSum = 0;
        for(char& c: s1) totalSum += c;
        for(char& c: s2) totalSum += c;
        return (totalSum - (2*(helper(s1,s2))));
    }
};