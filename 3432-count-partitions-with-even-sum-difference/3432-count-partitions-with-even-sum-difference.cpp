class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int>presum(n,0);
         presum[0] = nums[0];

        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }

        int cnt=0;

        for(int i=0;i<n-1;i++){
            int diff=abs(presum[i]-(presum[n-1]-presum[i]));

            if(diff%2==0){
                cnt++;
            }

        }
        return cnt;
    }
};