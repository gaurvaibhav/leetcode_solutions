class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0, cmax = 0, zs = 0, cmax2 = 0;
        for(char& it: s) {
            if(it == '0') {
                ones = max(ones,cmax);
                cmax = 0;
                cmax2++;
            }
            else {
                zs = max(zs,cmax2);
                cmax2 = 0;
                cmax++;
            }
        }
        ones = max(ones,cmax);
        zs = max(zs,cmax2);
        return ones > zs; 
    }
};