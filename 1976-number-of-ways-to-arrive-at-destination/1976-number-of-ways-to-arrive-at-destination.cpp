class Solution {    
private:
    int dijkstra(vector<pair<int, int>> adj[], int n) {
		int mod = 1e9 + 7;
       
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, 1e15), ways(n, 0);

        pq.push({0, 0});
        // mark the distance to 0
        dist[0] = 0;
        // mark the path number to 1
        ways[0] = 1;

        // until queue is not empty
        while (!pq.empty()) {
           
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

          
            for (auto &it : adj[node]) {
                int adjNode = it.first;
                long long wt = it.second;

                // if it min distance to reach at a node then update it
                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    pq.push({d + wt, adjNode});
                }
                else if (d + wt == dist[adjNode]) {
                    //if it already visited with the shortest dis then increse the path with the current node path
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // adjacency list
        vector<pair<int, int>> adj[n];

        // create the graph
        for (auto &v : roads) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        return dijkstra(adj, n);
    }
};
