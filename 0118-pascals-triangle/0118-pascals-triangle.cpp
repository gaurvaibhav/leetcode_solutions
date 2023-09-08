class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> aux(i+1);
            aux[0]=aux[aux.size()-1]=1;
            if(i>=2){
                for(int j=1;j<aux.size()-1;j++){
                    aux[j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
            ans.push_back(aux);
        }
        return ans;
    }
};