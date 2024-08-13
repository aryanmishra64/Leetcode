class Solution {
public:
    int find(vector<int>& arr, int target)
  {
      int n=arr.size();
      
      vector<vector<int>>dp(n,vector<int>(target+1,0));
      
      if(arr[0]==0) dp[0][0]=2;
      else dp[0][0]=1;
      
      if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;
      
      for(int ind=1;ind<n;ind++){
          for(int k=0;k<=target;k++){
              int notTake=dp[ind-1][k];
              
              int take=0;
              if(arr[ind]<=k){
                  take=dp[ind-1][k-arr[ind]];
              }
              dp[ind][k]=(notTake+take);
          }
      }
      return dp[n-1][target];
  }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        int n=nums.size();
       
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
     if(total-target <0 || (total-target)%2 ) return 0;
     
     return find(nums,(total-target)/2);
    }
};