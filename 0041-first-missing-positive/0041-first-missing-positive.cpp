#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        FASTIO;
        int m, mx = nums[0], i = 1;
        set<int> s;
        for(auto& it: nums) {
            m = min(m, it);
            mx = max(mx, it);
            if(it > 0) s.insert(it);
        }
        for(auto& it: s) {
            if(it != i) {
                return i;
            }
            i++;
        }
        if(s.empty()) return 1;
        return ++mx;
    }
};