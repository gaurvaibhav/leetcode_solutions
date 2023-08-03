#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    void solve(unordered_map<int,string>& mp, vector<string>& ans, string& ds, int ind, string& digits) {
        op;op;
        if(ds.size() == digits.size()) ans.push_back(ds);
        for(int i=ind; i<digits.size(); ++i) {
            ds.push_back(mp[digits[i]-'0'][0]);
            solve(mp,ans,ds,i+1,digits);
            ds.pop_back();
            ds.push_back(mp[digits[i]-'0'][1]);
            solve(mp,ans,ds,i+1,digits);
            ds.pop_back();
            ds.push_back(mp[digits[i]-'0'][2]);
            solve(mp,ans,ds,i+1,digits);
            ds.pop_back();
            if(digits[i] == '7' || digits[i] == '9') {
                ds.push_back(mp[digits[i]-'0'][3]);
                solve(mp,ans,ds,i+1,digits);
                ds.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        op;op;
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string aux;
        unordered_map<int,string> mp;
        mp.insert({2,"abc"});mp.insert({3,"def"});
        mp.insert({4,"ghi"});mp.insert({5,"jkl"});
        mp.insert({6,"mno"});mp.insert({7,"pqrs"});
        mp.insert({8,"tuv"});mp.insert({9,"wxyz"});
        solve(mp,ans,aux,0,digits);
        return ans;
    }
};