class Solution {
public:
    bool solve(int ind,long long prod1,long long prod2,vector<int>&nums,long long target,int n){

        if(prod1>target || prod2>target){
            return false;
        }
        if(ind==n){
            return (prod1==target && prod2==target);
        }

        bool a=solve(ind+1,prod1*nums[ind],prod2,nums,target,n);

        bool b=solve(ind+1,prod1,prod2*nums[ind],nums,target,n);

        return a|b;


    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();

        return solve(0,1,1,nums,target,n);
    }
};