class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj, vector<int>&color,int clr){

        color[node]=clr;

        for(auto it:adj[node]){
            if(color[it]==-1) dfs(it,adj,color,clr);
        }

    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>>adj(c+1);

        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int>color(c+1,-1);
        int clr=0;

        for(int i=1;i<=c;i++){
            if(color[i]==-1){
                dfs(i,adj,color,clr);
                clr++;
            }
        }

        vector<set<int>>v(clr);

        for(int i=1;i<=c;i++){
            v[color[i]].insert(i);
        }

        vector<int>ans;

        for(auto it:queries){
            int x=it[0];
            int y=it[1];
            if(x==1){
                if(v[color[y]].count(y)) ans.push_back(y);
                else if(v[color[y]].size()==0) ans.push_back(-1);
                else ans.push_back(*v[color[y]].begin());
            }
            else {
                if(v[color[y]].count(y)){
                    v[color[y]].erase(y);
            
                }
            }
        }
        return ans;
    }
};