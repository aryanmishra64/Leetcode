class Disjoin{
    public:

    vector<int>parent,size;
    int comp;

    Disjoin(int n){
        size.resize(n+1);
        parent.resize(n+1);

        comp=n;
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findupar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findupar(parent[node]);
    }

    void unionf(int u,int v){
        int ult_u=findupar(u);
        int ult_v=findupar(v);

        if(ult_u==ult_v) return;

        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else {
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        comp--;
    }



};


class Solution {
    
public:
   
    int minCost(int n, vector<vector<int>>& edges, int k) {

sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b)       {
    return a[2] < b[2];
});

        int ans=0;

        Disjoin ds(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            ds.unionf( u, v);

            if(ds.comp==k){
                ans=wt;
                break;

            }
        }
        
       return ans;



    }
};