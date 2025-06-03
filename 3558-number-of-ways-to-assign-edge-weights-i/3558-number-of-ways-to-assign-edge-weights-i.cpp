class Solution {
public:
     int MOD = 1e9 + 7;
    int dfs( int node,vector<vector<int>>&adj, vector<bool>&vis){

        vis[node]=true;
        int maxD=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                int d=dfs(it,adj,vis);
                maxD=max(maxD,d);
            }
        }

        
        return maxD+1;



    }
    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n=edges.size()+1;

        vector<vector<int>>adj(n+1);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n+1,false);
        int start=1;
        

        int dis=dfs(start,adj,vis);

      long long res = 1;
        for (int i = 0; i < dis - 1-1; ++i)
            res = (res * 2) % MOD;

        return res;

        
        
        
    }
};