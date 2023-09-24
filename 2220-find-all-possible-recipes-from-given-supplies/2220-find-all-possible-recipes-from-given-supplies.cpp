class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> s;
        for(auto& supply: supplies) s.insert(supply);
        int n = recipes.size();
        vector<bool> made(n, false);
        queue<int> q;
        for(int i=0; i<n; ++i) q.push(i);
        bool chk = true;
        while(chk) {
            chk = false;
            queue<int> aux;
            while(!q.empty()) {
                bool f = true;
                int i = q.front();
                q.pop();
                int m = ingredients[i].size();
                for(int j=0; j<m; ++j) {
                    if(s.find(ingredients[i][j]) == s.end()) {
                        f = false;
                        break;
                    }
                }
                if(f) {
                    s.insert(recipes[i]);
                    chk = true;
                    made[i] = true;
                }
                else {
                    aux.push(i);
                }
            }
            q = aux;
        }
        vector<string> res;
        for(int i=0; i<n; ++i) {
            if(made[i]) 
            res.push_back(recipes[i]);
        }
        return res;
    }
};