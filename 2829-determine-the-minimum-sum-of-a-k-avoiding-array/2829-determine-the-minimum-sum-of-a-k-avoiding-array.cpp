#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int minimumSum(int n, int k) {
        op;
        unordered_map<int, int> mp;
        int ind = 1, i=1 ,sum=0;
        while(true) {
            if(ind ==n+1) break;
            if(mp[k-i]) {
                i++;
            }
            else{
                mp[i]++;
                sum+=i;
                i++;
                ind++;
            }
        }
        return sum;
    }
};