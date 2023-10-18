class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> aux ;
        for(string x : strs)
        {
            string temp = x ;
            sort(temp.begin(), temp.end()) ;
            aux[temp].push_back(x) ;
        }
        vector<vector<string>> res ;
        for(auto keyValue : aux)
        {
            res.push_back(keyValue.second) ;
        }
        return res ;
    }
};