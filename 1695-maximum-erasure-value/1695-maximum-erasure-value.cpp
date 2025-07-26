class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>mpp;
        int l=0;
        int r=0;
        int sum=0;
        int ans=0;

        while(r<n){
            mpp[nums[r]]++;
            sum+=nums[r];

            while(mpp.size()!=(r-l+1)){
                sum-=nums[l];
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;

            }
            ans=max(ans,sum);
            r++;


        }
        return ans;

    
        
    }
};