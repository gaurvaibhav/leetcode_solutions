#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int minDeletions(string s) {
        FASTIO;
        int res = 0;
        vector<int> mp(26, 0);
        for(auto& c: s) mp[c-'a']++;
        unordered_set<int> chk;
        for (int i = 0; i < 26; ++i)
        {
            while( mp[i]>0 && !chk.insert(mp[i]).second ) {
                res++;
                mp[i]--;
            }
        }
        return res;
    }
};