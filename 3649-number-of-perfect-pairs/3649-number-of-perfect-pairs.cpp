class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]=-nums[i];
        }

        sort(nums.begin(),nums.end());

        long long cnt=0;
        int l=0;
        int r=0;

        while(r<n){

            while(nums[r]>2*nums[l]){
                l++;
            }
            cnt+=(r-l);
            r++;
        }
        return cnt;
    }
};