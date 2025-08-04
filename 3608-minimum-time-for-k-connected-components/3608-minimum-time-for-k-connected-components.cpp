class Disjoint{

    

    public:
    vector<int>size,parent;
    int comp;
    Disjoint(int n){
        size.resize(n+1);
        parent.resize(n+1);
        comp=n;
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }


    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
    void unionfind(int u,int v){
        int ult_u=findUpar(u);
        int ult_v=findUpar(v);
        if(ult_u==ult_v) return;

        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        comp--;

    }


};





class Solution {
public:

    
    int minTime(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[](const vector<int>&a,const vector<int>&b){
            return a[2]>b[2];
        });
        int ans=0;
    Disjoint ds(n);
    for(int i=0;i<edges.size();i++){
        int time=edges[i][2];
        int u=edges[i][0];
        int v=edges[i][1];
        ds.unionfind(u,v);
        if(ds.comp<k){
            ans=time;
            break;
        }
    }
    return ans;
        
    }
};