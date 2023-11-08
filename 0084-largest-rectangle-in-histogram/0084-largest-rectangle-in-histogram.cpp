class Solution
{
private:
    vector<int> prevSmaller(vector<int>& arr)
    { 
        int n, i;
        n = arr.size();
        vector<int> res(n);
        stack<int> s;
        for(i=0; i<n; ++i)
        {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if(s.empty()) res[i] = -1;
            else res[i] = s.top();
            s.push(i);
        }
        return res;
    }
    vector<int> nextSmaller(vector<int>& arr)
    { 
        int n, i;
        n = arr.size();   
        vector<int> res(n);
        stack<int> s;
        for(i=n-1; i>=0; --i)
        {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if(s.empty()) res[i] = n;
            else res[i] = s.top();
            s.push(i);
        }
        return res;
    }
public:
    int largestRectangleArea(vector<int>& arr)
    {
        int res, i, n, c;
        n = arr.size();
        res = INT_MIN;
        vector<int> ps, ns;
        ps = prevSmaller(arr);
        ns = nextSmaller(arr);
        for(i=0; i<n; ++i)
        {
            c = (ns[i] - ps[i] - 1) * arr[i];
            res = max(res, c);
        }
        return res;
    }
};