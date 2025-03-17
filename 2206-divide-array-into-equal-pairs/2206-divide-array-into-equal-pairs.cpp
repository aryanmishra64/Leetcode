class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int n=nums.size();
        
        int flag=0;

        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it:mpp){

            int val=it.second;
            if(val%2!=0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return true;
        }
        else {
            return false;
        }
       
    }
};