class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long  i=0;
        long long j=0;
        long long ans=0;

        while(i<n && j<n){

         if(nums[i]==0){


            while( j<n && nums[j]==0){
                j++;
            }
            long long size=(j-i);
            ans+=(size*(size+1))/2;

            i=j;
            
         }
         
         i++;
         j++;
         

            
        }
        return ans;

    }
};