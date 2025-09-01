class Solution {
public:
    int maxi=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        for(auto it:queries){
            int idx=it[0];
            int right=it[1];
            int k=it[2];
            int val=it[3];

            while(idx<=right){
                nums[idx] =(int) ((nums[idx] * val) % maxi);
                idx+=k;
            }
        }
        int ans=0;

        for(int i=0;i<n;i++){
            ans=ans^nums[i];
        }

        return ans;


    }
};