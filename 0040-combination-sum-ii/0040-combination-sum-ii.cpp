#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    void findC(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
        FASTIO;
        if(target < 0) return;
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            findC(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        FASTIO;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findC(0,target,candidates,ans,ds);
        return ans;
    }
};