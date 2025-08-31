class Solution {
public:
    int solve(int n,vector<vector<int>>adj[]){

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>dis(n,INT_MAX);
        dis[0]=0;

        pq.push({0,0});//node,wt

        while(!pq.empty()){
            int node=pq.top().first;
            int wt=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int next=it[0];
                int edgewt=it[1];

                if(dis[next]>wt+edgewt){
                    dis[next]=wt+edgewt;
                    pq.push({next,wt+edgewt});
                }

            }

            
        }
        return dis[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj[n];

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }

      int ans=  solve(n,adj);
      if(ans==INT_MAX){
        return -1;
      }

      return ans;
    }
};