class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%k==0){
            return 0;
        }
        else{

            int ans=sum%k;
            return ans;
           }
          }
};