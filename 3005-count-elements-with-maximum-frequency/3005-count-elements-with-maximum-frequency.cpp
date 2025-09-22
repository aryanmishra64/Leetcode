class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        int maxi=0;

        for(auto it:mpp){
            maxi=max(maxi,it.second);
        }

        int ans=0;

        for(auto it:mpp){

            if(it.second==maxi){
                ans+=maxi;
            }

        }
        return ans;
        
    }
};