#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        FASTIO;
        int mx = nums[0], i = 1;
        unordered_map<int, int> mp;
        for(auto& it: nums) {
            mx = max(mx, it);
            if(it > 0 && !mp[it]) mp[it]++;
        }
        for(auto& it: mp) {
            if(!mp[i]) return i;
            i++;
        }
        if(mp.empty()) return 1;
        return ++mx;
    }
};