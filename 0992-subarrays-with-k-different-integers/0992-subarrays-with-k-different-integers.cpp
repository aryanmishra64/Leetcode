class Solution {
public:
    
    int subArray(vector<int>& nums, int k)
    {
        int l=0;
        int r=0;
        int cnt=0;
        unordered_map<int,int>mpp;
        while(r<nums.size())
        {
            mpp[nums[r]]++;
            while(mpp.size()>k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                {
                    mpp.erase(nums[l]);
                }
                l=l+1;
            }
            cnt+=(r-l+1);
            r=r+1;
        }
        return cnt;
    }
    
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
          return subArray(nums, k) - subArray(nums, k - 1);
    }
};