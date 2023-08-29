#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int bestClosingTime(string customers) {
        FASTIO;
        int n=customers.length(), y=0, resi=-1, res=0;
        for (char& it: customers) 
        {
            if(it == 'Y') y++;
        }
        int ns = 0;
        res=INT_MAX;
        resi=n;
        for(int i=0; i<n; ++i) {
            if(customers[i] == 'Y') {
                if(res>y+ns) {
                    
                    res = y+ns;
                    resi = i;
                    
                }
                --y;
            }
            else{
                if(res>y+ns) {
                    
                    res = y+ns;
                    resi = i;
                    
                }
                ++ns;
            }
        }
        if(y+ns<res) return n;
        return resi;
	}
};