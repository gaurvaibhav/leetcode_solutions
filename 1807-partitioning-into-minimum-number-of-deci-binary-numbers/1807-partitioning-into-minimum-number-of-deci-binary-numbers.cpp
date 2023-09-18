class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for(char& it: n) {
          int t = ((int)(it-'0'));
          if(res < t) res = t; 
        }
        return res;
    }
};