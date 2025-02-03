class DisJointSet{
    public:
    vector<int>parent,size;

    DisJointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }

    }

    int Upar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=Upar(parent[node]);
    }

    void UnionBySize(int u,int v){
        int ulp_u=Upar(u);
        int ulp_v=Upar(v);

        if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];

        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);

        int extra=0;

        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            if(ds.Upar(u)==ds.Upar(v)){
                extra++;
            }
            else {
                ds.UnionBySize(u,v);
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cnt++;
            }
        }
        int ans=cnt-1;

        if(extra>=ans){
            return ans;
        }
        else {
         return -1;
    }
    }
};