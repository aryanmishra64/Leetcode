class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<long long,long long>mpp;

        int i=0;
        int j=0;
        long long  pairs=0;
        long long result=0;

        while(j<n){
            pairs+=mpp[nums[j]];
            mpp[nums[j]]++;

           while(pairs>=k){
            result+=(n-j);
            mpp[nums[i]]--;
            pairs-=mpp[nums[i]];
            i++;

           }
           j++;

        }
        return result;
    }
};