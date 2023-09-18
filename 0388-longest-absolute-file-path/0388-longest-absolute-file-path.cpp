class Solution {
public:
    int lengthLongestPath(string s) {
        if(s.empty()) return 0;
        vector<int> dfs;
        int res, cnt, dpt, isDir;
        res = cnt = dpt = 0;
        isDir = 1;
        for(int i=0; i<s.length()+1; ++i) {
            switch(s[i]) {
                case '\0':
                case '\n':
                    cnt = !dpt ? cnt + isDir: dfs[dpt-1] + cnt + isDir;
                    if(dfs.size() > dpt) dfs[dpt] = cnt;
                    else dfs.push_back(cnt);
                    if(!isDir) res = cnt > res ? cnt : res;
                    dpt = cnt = 0;
                    isDir = 1;
                    break;
                case '\t':
                    ++dpt;
                    break;
                case '.':
                    isDir = 0;
                default:
                    ++cnt;
            }
        }
        return res;
    }
};