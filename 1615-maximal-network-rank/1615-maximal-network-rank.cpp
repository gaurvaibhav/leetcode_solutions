#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        op;
        vector<int> aux(n);
        for(auto &road: roads) {
            aux[road[0]]++;
            aux[road[1]]++;
        }
        int mx=0, smx=0;
        for(int &it: aux) {
            if(it>mx) {
                smx = mx;
                mx = it;
            }
            else if(it>smx && it<mx) smx=it;
        }
        int mcnt,scnt;
        mcnt=scnt=0;
        for(int &it: aux) {
            if(it == mx) mcnt++;
            if(it == smx) scnt++;
        }
        if(mcnt>1) {
            int ed = 0;
            for(auto &road: roads) {
                if(aux[road[0]] == mx && aux[road[1]] == mx) ed++;
            }
            int mxe = mcnt*(mcnt-1)/2;
            return 2*mx-(mxe==ed?1:0);
        }
        int ed =0;
        for(auto &road: roads) {
            if((aux[road[0]]==mx && aux[road[1]]==smx)||(aux[road[0]]==smx && aux[road[1]]==mx))ed++;
        }
        return mx+smx-(scnt==ed?1:0);
    }
};