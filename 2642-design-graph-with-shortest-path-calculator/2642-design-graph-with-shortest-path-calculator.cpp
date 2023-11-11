#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define P pair<int, int>
class Graph
{
private:
    vector<vector<P>> adj;
    int dijkstra(int src, int des)
    {
        FASTIO;
        int n, weight, node, adjNode, newWeight, edgeLength;
        n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<P, vector<P>, greater<>> pq;
        pq.push({0, src});
        while(!pq.empty())
        {
            node = pq.top().second;
            weight = pq.top().first;
            pq.pop();
            if(weight > dist[node])
            {
                continue;
            }
            if(node == des)
            {
                return weight;
            }
            for(auto& edge: adj[node])
            {
                adjNode = edge.first;
                edgeLength = edge.second;
                newWeight = edgeLength + dist[node];
                if(dist[adjNode] > newWeight)
                {
                    dist[adjNode] = newWeight;
                    pq.push({newWeight, adjNode});
                }
            }
        }
        if(dist[des] == INT_MAX)
        {
            return -1;
        }
        return dist[des];
    }
public:
    Graph(int n, vector<vector<int>>& edges)
    {
        adj = vector<vector<P>>(n);
        for(auto& edge: edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge)
    {
        FASTIO;
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2)
    {
        FASTIO;
        return dijkstra(node1, node2);
    }
};