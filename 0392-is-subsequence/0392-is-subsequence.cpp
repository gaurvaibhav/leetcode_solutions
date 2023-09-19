class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j = 0;
        for(i = 0; i<t.length() && j<s.length(); ++i) 
        {
            if(s[j]==t[i]) ++j;
        }
        return (j == s.length());
    }
};