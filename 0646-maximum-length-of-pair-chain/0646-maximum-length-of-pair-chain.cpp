#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        FASTIO;
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        FASTIO;
        int res = 0;
        sort(pairs.begin(), pairs.end(), cmp);
        int start = 0;
        for(int i=0; i<pairs.size(); ++i) {
            if(i==0 || pairs[start][1]<pairs[i][0]) {
                res++;
                start = i;
            }
        }
        return res;
    }
};