#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        op;
        sort(batteries.begin(), batteries.end());
        long long res = 0 ;
        for(int value: batteries) res += value;
        for(int i=batteries.size()-1; i>=0; i--, n--) {
            if(batteries[i] <= (res/n)) break;
            res -= batteries[i];
        }
        return res/n;
    }
};