class Solution
{
    public:
    string reverseWords(string s) 
    {
        string ans;
        int i=0, n=s.length();
        while(i<n) {
            while(i<n && s[i]==' ') ++i;
            if(i>=n) break;
            int j=i;
            while(j<n && s[j]!=' ') j++;
            string temp = s.substr(i, j-i);
            if(ans.length()==0) ans = temp;
            else ans = temp + " " + ans;
            i = j+1;
            
        }
        return ans;
    } 
};