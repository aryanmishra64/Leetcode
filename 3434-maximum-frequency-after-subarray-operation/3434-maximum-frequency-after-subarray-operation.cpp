class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            if(nums[i]==k){
                cnt++;
            }
        }

        int ans=cnt;

        for(int i=1;i<=50;i++){
            if(i==k){
                continue;
            }

            int maxi=0;
            int gain=0;

            for(auto it:nums){

                if(gain<0){
                    gain=0;
                }

                if(it==i){
                    gain++;
                }
                else if(it==k){
                    gain--;
                }
                maxi=max(maxi,gain);
            }
            ans=max(ans,cnt+maxi);
            
        }

        return ans;


    }
};