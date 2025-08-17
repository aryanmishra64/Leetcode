class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();

        int i=0;
        int j=0;
        sort(nums.begin(),nums.end());
        long long mini=nums[0];
        long long  maxi=nums[0];
        int ans=0;

        while(j<n){
           
           mini=min(mini,1LL* nums[j]);
           maxi=max(maxi,1LL*nums[j]);

           while(maxi>mini*k){
            i++;
            mini=nums[i];
            
           }

           if(maxi<=mini*k){
            ans=max(ans,j-i+1);

           }
           j++;


            


        }
        return n-ans;
    }
};