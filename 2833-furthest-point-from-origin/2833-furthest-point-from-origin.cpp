#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        FASTIO;
        int l=0,r=0;
        int  n = moves.length();
        for(int i=0; i<n; ++i) {
            if(moves[i] == 'L') l++;
            else if(moves[i] == 'R') r++;
        }
        if(l>=r) {
            for(int i=0; i<n; ++i) {
                if(moves[i] == '_') moves[i] = 'L';
            }
        }
        else {
            for(int i=0; i<n; ++i) {
                if(moves[i] == '_') moves[i] = 'R';
            }
        }
        int res = 0;
        for(int i=0; i<n; i++) {
            if(moves[i] == 'L') res--;
            else res++;
        }
        return abs(res);
    }
};