class Solution {
private:
    int numberOfWords(string s)
    {
        int res = 0;
        for(char& c: s)
        {
            if(c == ' ') res++;
        }
        return ++res;

    }
public:
    string largestWordCount(vector<string>& m, vector<string>& s) {
        unordered_map<string, int> mp;
        priority_queue<pair<int, string>> pq;
        int n, i, w;
        n = s.size();
        for(i=0; i<n; ++i)
        {
            w = numberOfWords(m[i]);
            mp[s[i]] += w;   
        }
        for(auto& it: mp)
        {
            pq.push({it.second, it.first});
        }
        return pq.top().second;
    }
};