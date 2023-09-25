class Solution {
public:
    int beautySum(string s) {
        int res, n, i, j;
        n = s.length();
        res = 0;
        for(i=0; i<n; ++i) 
        {
            unordered_map<char, int> mp;
            multiset<int> st;
            for(j=i; j<n; ++j)
            {
                if(mp.find(s[j]) != mp.end())
                {
                    st.erase(st.find(mp[s[j]]));
                }
                mp[s[j]]++;
                st.insert(mp[s[j]]);
                res += (*st.rbegin() - *st.begin());
            }
        }
        return res;
    }
};