class Solution {
public:
    static int count1s(int n) {
        int res = 0 ;
        while(n) {
            res++ ;
            n = n & (n-1) ;
        }
        return res ;
    }
    static bool compare(int n1, int n2) {
        int a = count1s(n1) ;
        int b = count1s(n2) ;
        if(a == b) {
            return (n1 <= n2) ;
        }
        return (a < b) ;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare) ;
        return arr ;
    }
};