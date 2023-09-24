class Solution {
private:
    void solve(int open, int close, string& ds, vector<string>& res) {
        if(!open && !close) {
            res.push_back(ds);
            return;
        }
        if(open) {
            ds.push_back('(');
            solve(open-1, close, ds, res);
            ds.pop_back();
        }
        if(close > open) {
            ds.push_back(')');
            solve(open, close-1, ds, res);
            ds.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open, close;
        open = close = n;
        string ds = "";
        vector<string> res;
        solve(open, close, ds, res);
        return res;
    }
};