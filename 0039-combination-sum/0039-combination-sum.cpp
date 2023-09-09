#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    void findC(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
        op;
        if(ind>=arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findC(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findC(ind+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        op;
        vector<vector<int>> ans;
        vector<int> ds;
        findC(0,target,candidates,ans,ds);
        return ans;
    }
};