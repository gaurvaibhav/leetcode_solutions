#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    void solve(int ind, int k, int n, vector<int>& aux, vector<vector<int>>& ans) {
        FASTIO;
        if(k<0 || n<0) return;
        if(k == 0 && n == 0) {
            ans.push_back(aux);
            return ;
        }
        for(int i=ind; i<=9; ++i) {
            aux.push_back(i);
            solve(i+1, k-1, n-i, aux, ans);
            aux.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        FASTIO;
        vector<int> aux;vector<vector<int>> ans;
        solve(1, k, n, aux, ans);
        return ans;
    }
};