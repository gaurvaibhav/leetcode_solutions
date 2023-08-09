#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int minimizeMax(vector<int>& A, int p) {
        op;
        sort(A.begin(), A.end());
        int n = A.size(), st = 0, e = A[n - 1] - A[0];
        while (st < e) {
            int mid = (st + e) / 2, k = 0;
            for (int i = 1; i < n && k < p; ++i) {
                if (A[i] - A[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }
            if (k >= p)
                e = mid;
            else
                st = mid + 1;
        }
        return st;
    }
};