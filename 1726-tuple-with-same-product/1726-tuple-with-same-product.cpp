class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;


        for(int i=0;i<n;i++){
            for(int  j=i+1;j<n;j++){
                mpp[nums[i]*nums[j]]++;

            }
        }
        int ans=0;
        for(auto it:mpp){
            int x=it.second;
            ans+=(x*(x-1))/2;
        }
        return ans*8;
    }
};