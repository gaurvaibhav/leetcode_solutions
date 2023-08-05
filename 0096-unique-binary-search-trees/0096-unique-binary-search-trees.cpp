#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    long ncr(int n, int r) {
        op;op;
        long res = 1;
        for(int i = 0; i < r; i++) {
            res *= n-i;
            res /= i+1;
        }
        return res; 
    }
public:
    int numTrees(int n) {
        op;op;
        return ((ncr(2*n, n)) / (n + 1));
    }
};