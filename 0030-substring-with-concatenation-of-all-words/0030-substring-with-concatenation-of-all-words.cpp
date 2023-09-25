class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n, m, k;
        n = words.size();
        m = words[0].size();
        k = n*m;
        unordered_map<string, int> aux;
        vector<int> ans;
        for(auto& it: words) aux[it]++;
        if(k > s.length()) return ans;
        for(int i=0; i<m; i++)
        {
            unordered_map<string, int> mp;
            int l = i;
            for(int j = i; j <= s.length()-m; j+=m)
            {
                string temp = s.substr(j, m);
                if(aux.find(temp) != aux.end())
                {
                    mp[temp]++;
                    while(mp[temp] > aux[temp])
                    {
                        mp[s.substr(l, m)]--;
                        l += m;
                    }
                    if(j - l + m == k)
                    {
                        ans.push_back(l);
                        mp[s.substr(l, m)]--;
                        l += m;
                    }
                }
                else
                {
                    mp.clear();
                    l = j+m;
                }
            }
        }
        return ans;
    }
};