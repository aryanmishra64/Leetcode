class Solution {
public:
    void helper(int ind, int tempOr, vector<int>&nums,int& maxOr,int& cnt){
        int n=nums.size();

        if(ind==n){
            if(tempOr==maxOr){
                cnt++;
            }
            return;
        }

        helper(ind+1,tempOr | nums[ind],nums,maxOr,cnt);
        helper(ind+1,tempOr,nums,maxOr,cnt);
    }


    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();

        int maxOr=0;
        for(int i=0;i<n;i++){
            maxOr=maxOr | nums[i];
        }

        int tempOr=0;
        int ans=0;
        helper(0,tempOr,nums,maxOr,ans);
        return ans;
    }
};