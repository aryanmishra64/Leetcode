class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);

        for(int j=1;j<n;j++){
            prefix[j]=max(prefix[j-1],nums[j-1]);
        }
        for(int j=n-2;j>=0;j--){
            suffix[j]=max(suffix[j+1],nums[j+1]);
        }
        long long result=0;

        for(int j=1;j<n;j++){
            result=max(result,(long long)(prefix[j]-nums[j])*suffix[j]);
        }
        return result;
    }
};