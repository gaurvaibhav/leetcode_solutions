class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        for(int i=0; i<n; ++i) 
            mp[arr[i]].push_back(i);
        vector<vector<int>> ans;
        for(auto& it: mp) {
            vector<int> aux;
            int c = it.first;
            for(int i=0; i<it.second.size(); ++i) {
                if(!c) {
                    ans.push_back(aux);
                    c = it.first;
                    aux.clear();
                }
                aux.push_back(it.second[i]);
                c--;
            }
            ans.push_back(aux);
        } 
        return ans;  
    }
};