class Solution {
public:
    void helper(int ind,int temp,vector<int>& nums,int& ans){
        int n=nums.size();
        if(ind==n){
            ans+=temp;
            return;
        }

        helper(ind+1,temp ^ nums[ind],nums,ans);
        helper(ind+1,temp,nums,ans);
    }


    int subsetXORSum(vector<int>& nums) {
        int temp=0;
        
        int ans=0;

        helper(0,temp,nums,ans);
        return ans;
    }
};