class Solution {
public:
    int dfs(int node,  vector<vector<int>>&adj,int d,vector<bool>&vis){
        if(d<0){
            return 0;
        }

        vis[node]=true;
        int count=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                count+=dfs(it,adj,d-1,vis);
            }
        }
        return count;



    }
    vector<int>findcount(vector<vector<int>>& edges,int d){
        int n=edges.size()+1;

        vector<vector<int>>adj(n);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>result(n,0);
       
        for(int i=0;i<n;i++){
            vector<bool> vis(n, false);
            result[i]=dfs(i,adj,d,vis);
        }
        return result;
    }


     
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        int n=edges1.size()+1;

        vector<int>res1=findcount(edges1,k);
        vector<int>res2=findcount(edges2,k-1);

        int maxi=*max_element(begin(res2), end(res2));

        for(int i=0;i<res1.size();i++){

            res1[i]+=maxi;

        }
        return res1;

        


        
    }
};