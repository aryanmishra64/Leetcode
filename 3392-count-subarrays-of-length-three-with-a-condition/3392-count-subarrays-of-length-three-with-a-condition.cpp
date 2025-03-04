class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        
        int n=nums.size();
        int cnt=0;

       for(int i=0;i<n-2;i++){
          int x=nums[i];
          int y=nums[i+1];
          int z=nums[i+2];
          if((x+z)==(y/2)){
            cnt++;
          }

       }
       return cnt;
    }
};