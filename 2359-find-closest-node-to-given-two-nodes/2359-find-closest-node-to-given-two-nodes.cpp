class Solution {
public:
    vector<int>bfs(int n,vector<int>& edges,int src){

        vector<int>dis(n,1e9);

        queue<pair<int,int>>q;
        q.push({src,0});
        dis[src]=0;

        while(!q.empty()){
            int node=q.front().first;
            int edWt=q.front().second;
            q.pop();

            if(edges[node]==-1){
                continue;
            }

            if(dis[edges[node]]>1+edWt){
                dis[edges[node]]=1+edWt;
                q.push({edges[node], 1+edWt});
            }



        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();

        vector<int>dist1=bfs(n,edges,node1);
        vector<int>dist2=bfs(n,edges,node2);

        int mini=INT_MAX;
        int minNode=-1;

        for(int i=0;i<n;i++){
            if (dist1[i] == 1e9 || dist2[i] == 1e9) continue;

            int maxD=max(dist1[i],dist2[i]);
            if(mini>maxD){
                mini=maxD;
                minNode=i;
            }

        }
        return minNode;


    }
};