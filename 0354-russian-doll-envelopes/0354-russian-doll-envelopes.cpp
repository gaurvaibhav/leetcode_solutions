class Solution {
private:
    int LIS(int n, vector<vector<int>>& arr) {
        if(!n) return 0;
        vector<int> ans;
        ans.push_back(arr[0][1]);
        for(int i=1; i<n; ++i) {
            if(arr[i][1] > ans.back()) {
                ans.push_back(arr[i][1]);
            }
            else {
                int ind = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();
                ans[ind] = arr[i][1];
            }
        }
        return ans.size();
    }
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n;
        vector<int> aux;
        sort(arr.begin(), arr.end(), cmp);
        n = arr.size();
        return LIS(n, arr);
    }
};