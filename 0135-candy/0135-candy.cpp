#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int candy(vector<int>& ratings) {
      FASTIO;
      int n = ratings.size();
      vector<int> candyArr(n, 1);
      for(int i=1; i<n; ++i) {
        if(ratings[i] > ratings[i-1] && candyArr[i] <= candyArr[i-1]) {
          candyArr[i] = candyArr[i-1]+1;
        }
      }
      for(int i=n-2; i>=0; --i) {
        if(ratings[i] > ratings[i+1] && candyArr[i] <= candyArr[i+1]) {
          candyArr[i] = candyArr[i+1]+1;
        }
      }
      int res = 0;
      for(int& it: candyArr) res += it;
      return res;
    }
};