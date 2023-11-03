class Solution
{
public:
    vector<string> buildArray(vector<int>& arr, int n)
    {
        int i, c, m;
        m = arr.size();
        c = 1;
        vector<string> res;
        for(i=0; i<m; ++i)
        {
            while(c < arr[i])
            {
                ++c;
                res.push_back("Push");
                res.push_back("Pop");
            }
            ++c;
            res.push_back("Push");
        }
        return res;
    }
};