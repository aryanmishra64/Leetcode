class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&path,vector<int>&check ){
        vis[node]=1;
        path[node]=1;
        check[node]=0;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,path,check)==true){
                    check[node]=0;
                    return true;
                }
            }
            else if(path[it]){
                check[node]=0;
                return true;
            }
        }

        check[node]=1;
        path[node]=0;
        return false;


    }



    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>vis(n,0);
        vector<int>path(n,0);
        vector<int>check(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,path,check);
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;






    }
};