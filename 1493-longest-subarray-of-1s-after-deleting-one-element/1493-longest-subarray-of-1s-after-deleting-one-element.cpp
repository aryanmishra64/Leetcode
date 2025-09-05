class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;

        for(int i=0;i<n;i++){
            if(nums[i]!=1){
                flag=true;
                break;
            }
        }
        if(flag==false){
            return n-1;
        }

        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;

        while(j<n){

            if(nums[j]==0){
                
                cnt++;
            }

            while(cnt>1){
                if(nums[i]==0){
                    cnt--;
                }
                i++;

            }
            if(cnt<=1){
                 ans=max(ans,j-i);

            }
           
            j++;

        }
        return ans;
    }
};