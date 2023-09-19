class Solution {
private:
    string solve(int& i, string s) {
        string res = "";
        int n = 0;
        while(i<s.length()) {
            if(s[i] == '[') {
                ++i;
                string str = solve(i, s);
                while(n > 0) {
                    res += str;
                    n--;
                }
            }
            else if(s[i] == ']') 
                return res;
            else if(s[i]>='0' && s[i]<='9') 
                n = n * 10 + s[i] - '0';
            else 
                res += s[i];
            ++i;
        }
        return res;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return solve(i, s);
    }
};