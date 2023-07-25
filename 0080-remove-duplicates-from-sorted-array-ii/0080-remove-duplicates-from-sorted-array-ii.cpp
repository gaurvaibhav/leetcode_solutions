#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        op;
        int k=0;
        for(auto element: nums) {
            if(k<2 || element!= nums[k-2]) {
                nums[k++] = element;
            }
        }
        return k;
    }
};