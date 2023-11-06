class SeatManager
{
private:
    priority_queue <int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n)
    {
        pq = priority_queue <int, vector<int>, greater<int>> ();
        for(int i=1; i<=n; ++i)
        {
            pq.push(i);
        }
    }
    
    int reserve()
    {
        int res = pq.top();
        pq.pop();
        return res;
    }
    
    void unreserve(int i)
    {
        pq.push(i);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */