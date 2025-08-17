class Solution {
public:
    int earliestFinishTime(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {

        int n=start1.size();
        int m=start2.size();
        int min_land=INT_MAX;
        int min_water=INT_MAX;

        for(int i=0;i<n;i++){
            min_land=min(min_land,start1[i]+end1[i]);
        }
        for(int j=0;j<m;j++){
            min_water=min(min_water,start2[j]+end2[j]);
        }

        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            int strt=max(min_land,start2[i]);
            ans=min(ans,strt+end2[i]);

        }
          for(int i=0;i<n;i++){
            int strt=max(min_water,start1[i]);
            ans=min(ans,strt+end1[i]);

        }
        return ans;

        
        
    }
};