class Solution {
public:
    int minimumSum(int n, int k) {
        int i = 1, cnt = 0, res= 0;
        unordered_map<int, int> mp;
        while(cnt < n) {
            if(!mp[k-i]) {
                mp[i]++;
                res += i;
                cnt++;
            }
            i++;
        }
        return res;
    }
};