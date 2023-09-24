class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> mat(101, vector<double> (101, 0.0));
        mat[0][0] = poured;
        for(int i=0; i<100; i++) {
            for(int j=0; j<=i; j++) {
                if(mat[i][j] >= 1) {
                    mat[i+1][j] += (mat[i][j] - 1) / 2.0;
                    mat[i+1][j+1] += (mat[i][j] - 1) / 2.0;
                    mat[i][j] = 1;
                }
            }
        }
        return mat[query_row][query_glass];
    }
};