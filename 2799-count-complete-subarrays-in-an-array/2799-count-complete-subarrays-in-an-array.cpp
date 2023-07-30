#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        op;op;op;op;op;op;op;op;op;op;op;op;op;op;
        int n = nums.size();
        unordered_set<int> mset;
        for(int& value: nums) mset.insert(value);
        int s = mset.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            unordered_set<int> aux;
            for(int j=i; j<n; j++) {
                aux.insert(nums[j]);
                if(aux.size() == s) res++;
            }
        }
        return res;
    }
};