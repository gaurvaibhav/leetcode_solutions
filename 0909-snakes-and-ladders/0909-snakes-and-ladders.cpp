#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private: 
    pair<int, int> coordinates(int x, int n) {
        FASTIO;
        int r = n - (x-1)/ n-1;
        int c = (x-1) % n;
        if(r%2 == n%2) {
            return {r,n-1-c};
        }
        return {r,c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        FASTIO;
        queue<int> q;
        int steps=0,n=board.size();
        vector<vector<int>> vis(n, vector<int> (n,0));
        q.push(1);
        vis[n-1][0] = 1;
        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; ++i){
                int f = q.front();
                q.pop();
                if(f == n*n) return steps;
                for(int j=1; j<=6; ++j) {
                    if(j+f > n*n) break;
                    pair<int, int> coor = coordinates(j+f, n);
                    int r = coor.first;
                    int c = coor.second;
                    if(!vis[r][c]) {
                        vis[r][c] = true;
                        if(board[r][c] == -1) q.push(f+j);
                        else q.push(board[r][c]);
                    }
                }   
            }
            ++steps;
        }
        return -1;
    }
};