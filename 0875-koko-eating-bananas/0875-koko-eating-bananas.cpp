class Solution {
private:
    long long solve(vector<int>& arr, int k) {
        long long res = 0;
        for(auto& it: arr) {
            long long t = it/k;
            res += ceil(((double)it) / ((double)k));
        }
        return res;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxc = 0;
        for(auto& it: piles) {
            if(maxc<it) maxc=it;
        }
        long long l = 1, e = maxc;
        while(l<=e) {
            long long mid = l+(e-l)/2;
            long long aux = solve(piles, mid);
            if(aux<=h) {
                e=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};