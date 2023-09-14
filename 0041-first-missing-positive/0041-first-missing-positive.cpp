#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        FASTIO;
        unordered_map<int, int> mp;
        for(auto& it: nums) {
            mp[it]++;
        }
        for(int i=1; i<=nums.size()+1; ++i) {
            if(!mp[i]) return i;
        }
        return 1;
    }
};