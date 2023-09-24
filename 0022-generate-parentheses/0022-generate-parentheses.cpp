class Solution {
private:
    void solve(int open, int close, string& ds, vector<string>& res) {
        if(!open && !close) {
            res.push_back(ds);
            return;
        }
        if(open) {
            string op1 = ds;
            op1.push_back('(');
            solve(open-1, close, op1, res);
        }
        if(close > open) {
            string op2 = ds;
            op2.push_back(')');
            solve(open, close-1, op2, res);
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