#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        op;op;        
        int m=matrix.size(),n=matrix[0].size();
        int s = 0,e = (m*n)-1;
        int mid;
        while(s<=e){
            mid = s+(e-s)/2;
            int r = mid/n,c=mid%n;
            if(matrix[r][c]==target) return true;
            else if (matrix[r][c]>target) e=mid-1;
            else s=mid+1;
        }
        return false;
        
    }
};