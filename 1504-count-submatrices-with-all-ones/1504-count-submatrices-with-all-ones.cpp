class Solution {
public:
    int solve(vector<int>&v){
        int cons=0;
        int tot=0;

        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                cons=0;
            }
            else {
                cons++;
            }
            tot+=cons;
        }
        return tot;
    }
    int numSubmat(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        int res=0;

        for(int start=0;start<n;start++){
            vector<int>v(m,1);
            for(int end=start;end<n;end++){

                for(int col=0;col<m;col++){
                    v[col]=v[col]&mat[end][col];
                }

                res+=solve(v);



            }
        }
        return res;
    }
};