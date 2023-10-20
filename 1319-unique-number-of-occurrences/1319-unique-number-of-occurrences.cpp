class Solution
{
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> mp, freq;
        for(int& i: arr) mp[i]++;
        for(auto& it: mp) freq[it.second]++;
        for(auto& it: freq) if(it.second != 1) return false;
        return true;
    }
};