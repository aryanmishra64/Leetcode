class Solution {
public:
    bool check(vector<int>& nums) {
     int cnt=0;
     int len=nums.size();
     for(int i=1;i<len;i++)
     {
         if(nums[i-1]>nums[i])
         {
             cnt++;
         }
     }
       if(nums[len-1]>nums[0])
       {
           cnt++;
       }
       if(cnt<=1)
       {
           return true;
       }
       else {
           return false;
       }
    }
};