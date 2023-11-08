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
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int n, m, i, j, res;
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> arr(n, vector<int> (m));
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                arr[i][j] = matrix[i][j] - '0';
            }
        }
        vector<int> curr = arr[0];
        res = largestRectangleArea(curr);
        for(i=1; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                if(arr[i][j] == 1)
                {
                    curr[j] += 1;
                }
                else 
                {
                    curr[j] = 0;
                }
            }
            res = max(res, largestRectangleArea(curr));
        }
        return res;
    }
};