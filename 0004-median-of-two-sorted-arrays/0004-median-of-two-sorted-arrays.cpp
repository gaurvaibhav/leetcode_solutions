class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i, j, n ,m;
        i = j = 0;
        n = nums1.size();
        m = nums2.size();
        while(i<n && j < m) {
            if(nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n) {
            res.push_back(nums1[i]);
            i++;
        }
        while(j<m) {
            res.push_back(nums2[j]);
            j++;
        }
        if(res.size()%2) {
            return (double)(res[(res.size()-1)/2]);
        }
        return (double)((double)res[res.size()/2] + (double)res[(res.size()-1)/2])/2.0;
    }
};