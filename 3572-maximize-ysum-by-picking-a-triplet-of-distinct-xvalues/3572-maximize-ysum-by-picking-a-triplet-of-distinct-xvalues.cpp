class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        
        int n=x.size();

        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
             if (mpp.find(x[i]) != mpp.end()){
                if(mpp[x[i]]<y[i]){
                    mpp[x[i]]=y[i];
                }
            }
            else {
                mpp[x[i]]=y[i];

            }
            
        }
        if(mpp.size()<3){
            return -1;
        }

        vector<int>ans;

        for(auto it:mpp){
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        int m=ans.size();
        int res=ans[m-1]+ans[m-2]+ans[m-3];

        return res;
    }
};