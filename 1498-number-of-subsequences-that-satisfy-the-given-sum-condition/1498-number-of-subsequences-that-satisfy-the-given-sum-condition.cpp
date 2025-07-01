class Solution {
public:
    int M=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());

        vector<int>power(n);
        power[0]=1;

        int ans=0;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%M;
        }

        int l=0;
        int r=n-1;
        while(r>=l){

            if(nums[l]+nums[r]<=target){
                int diff=r-l;
                ans=(ans%M+power[diff])%M;
                l++;
            }
            else {
                r--;
            }

        }
        return ans;

       

        

    }
};