#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        op;
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); ++i) pq.push(nums[i]);
        k--;
        while(k--) pq.pop();
        return pq.top();
    }
};