class Solution {
public:
    vector<int> countBits(int n) {
        ios_base::sync_with_stdio(false) ;
        cin.tie(NULL) ;
        cout.tie(NULL) ;
        vector<int> arr(n+1, 0) ;
        for(int i=1; i<=n; ++i) {
            if(i&1) arr[i] = arr[i-1] + 1 ; 
            else arr[i] = arr[i/2] ;
        }
        return arr ;
    }
};