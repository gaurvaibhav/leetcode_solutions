#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        FASTIO;
        int minl=0,maxl=0,cnt=0;
        while(maxl < n) {
            for(int i=0; i<ranges.size(); ++i) {
                if(i-ranges[i]<=minl && i+ranges[i]>maxl) {
                    maxl = i+ranges[i];
                }
            }
            if(minl == maxl) return -1;
            ++cnt;
            minl = maxl;            
        }
        return cnt;
    }
};