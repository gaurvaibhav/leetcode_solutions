class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        int k;
        string res;
        res = "";
        for(char& c: s)
        {  
            mp[c]++;
        }
        for(auto& it: mp)
        {
            pq.push({it.second, it.first});
        }
        while(!pq.empty())
        {
            k = pq.top().first;
            while(k)
            {
                res += pq.top().second;
                k--;
            }
            pq.pop();
        }
        return res;
    }
};