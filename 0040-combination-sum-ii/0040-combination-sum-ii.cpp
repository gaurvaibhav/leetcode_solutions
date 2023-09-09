class Solution {
public:
    void findC(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds, int n){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            findC(i+1,target-arr[i],arr,ans,ds,n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findC(0,target,candidates,ans,ds,candidates.size());
        return ans;
    }
};