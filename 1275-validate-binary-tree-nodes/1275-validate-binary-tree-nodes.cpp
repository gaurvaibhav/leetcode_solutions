class Solution
{
private:
    void solve(vector<int>& l, vector<int>& r, int root, vector<bool>& vis)
    {
        if(root==-1 || vis[root])
        {
            return;
        }
        vis[root] = true;
        solve(l, r, l[root], vis);
        solve(l, r, r[root], vis);
        return;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r)
    {
        int i, root;
        vector<bool> vis(n, false);
        vector<int> indegree(n, 0);
        for(i=0; i<n; ++i)
        {
            if(l[i] != -1 && ++indegree[l[i]] > 1)
            {
                return false;
            }
            if(r[i] != -1 && ++indegree[r[i]] > 1)
            {
                return false;
            }
        }
        root = -1;
        for(i=0; i<n; ++i)
        {
            if(!indegree[i])
            {
                if(root!=-1) return false;
                root = i;
            }
        }
        if(root==-1) return false;
        solve(l, r, root, vis);
        for(auto s: vis)
        {
            if(!s)
            {
                return false;
            }
        }
        return true;
    }
};