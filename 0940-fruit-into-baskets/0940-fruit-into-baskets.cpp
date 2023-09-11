class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size(),i=0,j=0,res=0;
        unordered_map<int, int> mp;
        while(j<n) {
            mp[arr[j]]++;
            while(mp.size()>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                    mp.erase(arr[i]);
                i++;
            }
            if(mp.size()<=2) res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};