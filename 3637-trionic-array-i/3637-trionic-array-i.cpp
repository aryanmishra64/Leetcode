class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int flag1=0;
        int flag2=0;
        int flag3=0;
        int n=nums.size();
        int i=0;
        int j=1;

        while(j<n && nums[i]<nums[j]){
            flag1=1;
            i=j;
            j++;

        }
        if(j>=n || nums[i]==nums[j]){
            return false;
        }
         while(j<n && nums[i]>nums[j]){
            flag2=1;
            i=j;
            j++;

        }
        if(j>=n || nums[i]==nums[j]){
            return false;
        }
         while(j<n && nums[j]>nums[i]){
            flag3=1;
            i=j;
            j++;

        }
        if(j!=n){
            return false;
        }

        return (flag1 && flag2 && flag3);

        

    }
};