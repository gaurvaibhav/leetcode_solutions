#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    string longestPalindrome(string s) {
        op;
        if(s.empty()) return "" ;
        if(s.length() == 1) return s ;
        int l = 0, r = 1 ;
        for(int i=0; i<s.length(); ) {
            if(s.length()-i <= r/2) break ;
            int lPart = i, rPart = i ;
            while(rPart < s.length()-1 && s[rPart+1] == s[rPart]) rPart++ ;
            i = rPart + 1 ;
            while(rPart < s.length()-1 && lPart > 0 && s[rPart+1] == s[lPart-1]) {
                rPart++ ;
                lPart-- ;
            }
            int curr = rPart - lPart + 1 ;
            if(curr > r) {
                l = lPart ;
                r = curr ;
            }
        }
        return s.substr(l, r) ;
    }
};