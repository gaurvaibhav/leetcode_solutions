#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        op;
        vector<int> r(9,0),c(9,0),b(9,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int Bmask = 1<<(board[i][j]-'0');
                    if(r[i]&Bmask||c[j]&Bmask||b[i/3*3+j/3]&Bmask)
                    return false;
                    r[i] |= Bmask;
                    c[j] |= Bmask;
                    b[i/3*3+j/3] |= Bmask;
                }
            }
        }
        return true;
    }
};