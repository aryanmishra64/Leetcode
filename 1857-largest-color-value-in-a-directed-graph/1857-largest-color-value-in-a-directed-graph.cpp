class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>adj(n);
        vector<int>ind(n,0);


        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            ind[v]++;
        }
        queue<int>q;
        vector<vector<int>>t(n,vector<int>(26,0));

        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                t[i][colors[i]-'a']=1;
            }
        }

        int answer =0;
        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            cnt++;
            answer=max(answer,t[node][colors[node]-'a']);

            for(int &it:adj[node]){
                for(int i=0;i<26;i++){
                    t[it][i]=max(t[it][i],t[node][i]+(colors[it]-'a'==i));
                }
                ind[it]--;
            if(ind[it]==0){
                q.push(it);
            }
            }
            
        }
        if(cnt<n){
            return -1;
        }
        else  {
            return answer;
        }

        
        


        

    }
};