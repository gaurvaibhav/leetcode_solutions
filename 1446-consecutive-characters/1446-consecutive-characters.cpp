class Solution {
public:
    int maxPower(string s) {
        int res=0, cmax =0, n=s.length();
        if(n ==1 ) return 1;
        for(int i=0; i<n-1; ++i ) {
            if(s[i]!=s[i+1] ) {
                cmax++;
                res = max(res,cmax);
                cmax = 0;
            }
            else if(i==n-2) cmax+=2;
            else cmax++;
        }
        res = max(res,cmax);
        return res;
    }
};