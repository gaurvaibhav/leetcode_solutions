class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= 1 || numRows == 1) {
            return s ;
        }
        int n = s.length() ; 
        vector<string> aux(numRows) ;
        int progression = 0, currRow = 0 ;
        for(int i=0 ; i<n ; i++) {
            aux[currRow].push_back(s[i]) ;
            if(currRow == 0) progression = 1 ;
            else if(currRow == numRows - 1) progression = -1 ;
            currRow += progression ;
        }
        s = "";
        for(int i=0 ; i<numRows ; i++) {
            s += aux[i] ;
        }
        return s ;
    }
};