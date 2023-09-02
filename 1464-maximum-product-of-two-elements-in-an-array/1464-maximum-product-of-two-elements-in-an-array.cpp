class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto& it: nums) pq.push(it);
        int res = 1;
        res *= pq.top()-1;
        pq.pop();
        res *= pq.top()-1;
        return res;
    }
};