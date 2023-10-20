#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class NestedIterator
{
private:
    vector<int> res;
    int ind = 0;
    void solve(NestedInteger num)
    {
        FASTIO;
        if(num.isInteger())
        {
            res.push_back(num.getInteger());
        }
        else 
        {
            for(auto it: num.getList())
            {
                solve(it);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for(auto it: nestedList)
        {
            solve(it);
        }
    }
    
    int next()
    {
        FASTIO;
        return res[ind++];
    }
    
    bool hasNext()
    {
        FASTIO;
        return ind < res.size();
    }
};