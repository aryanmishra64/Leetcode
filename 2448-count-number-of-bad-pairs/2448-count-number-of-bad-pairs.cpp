class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();

        long long total=(n*(n-1))/2;

        unordered_map<long long ,long long >mpp;
        long long cnt=0;

        for(int i=0;i<n;i++){

            int val=nums[i]-i;

            if(mpp.find(val)!=mpp.end()){
                cnt+=mpp[val];
            }
            mpp[val]++;

        }
        long long ans=total-cnt;
        return ans;
    }
};