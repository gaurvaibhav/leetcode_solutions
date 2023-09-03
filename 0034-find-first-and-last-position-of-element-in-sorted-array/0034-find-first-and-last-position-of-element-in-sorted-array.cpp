#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    int firstOcc(vector<int>& arr, int t) {
        FASTIO;
        int ans = -1, i=0, j=arr.size()-1, mid;
        while(i<=j) {
            mid = i+(j-i)/2;
            if(arr[mid] >= t) {
                if(arr[mid] == t) ans = mid;
                j = mid-1;
            }else i = mid+1;
        }
        return ans;
    }
    int lastOcc(vector<int>& arr, int t) {
        FASTIO;
        int ans = -1, i=0, j=arr.size()-1, mid;
        while(i<=j) {
            mid = i+(j-i)/2;
            if(arr[mid] <= t) {
                if(arr[mid] == t) ans = mid;
                i = mid+1;
            }else j = mid-1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        FASTIO;
        vector<int> ans;
        ans.push_back(firstOcc(nums, target));
        ans.push_back(lastOcc(nums, target));
        return ans;
    }
};