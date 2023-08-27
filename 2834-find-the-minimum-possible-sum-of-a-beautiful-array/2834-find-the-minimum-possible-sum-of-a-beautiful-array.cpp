#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
class Solution {
public:
    ll minimumPossibleSum(int n, int target) {
        FASTIO;
        unordered_map<int, int> mp;
        ll res = 1;
        int i = 1;
        mp[i] = 1;
        ++i;n--;
        while(n>0){
            if(mp[target-i] == 0 && mp[i] == 0) {
                res += i;
                mp[i] = 1;
                n--;
            }
            ++i;
        }
        return res;
    }
};