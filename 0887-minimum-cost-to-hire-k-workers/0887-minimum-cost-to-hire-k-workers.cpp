class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector<pair<double, int>> arr;
        priority_queue<int> pq;
        int n;
        double ratio, qsum, ans;
        ans = DBL_MAX;
        qsum = 0;
        n = q.size();
        for(int i=0; i<n; ++i)
        {
            ratio = (double)w[i]/q[i];
            arr.push_back({ratio, q[i]});
        }
        sort(arr.begin(), arr.end());
        for(auto& it: arr)
        {
            qsum += it.second;
            pq.push(it.second);
            if(pq.size() > k)
            {
                qsum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
            {
                ans = min(ans, it.first*qsum);
            }
        }
        return ans;
    }
};