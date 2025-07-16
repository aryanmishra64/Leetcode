class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int odd=0;
        int even=0;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even++;
            }
            else {
                odd++;
            }
        }

        int alt=1;
        int parity=nums[0]%2;

        for(int i=1;i<n;i++){
            int curr=nums[i]%2;
            if(curr!=parity){
                alt++;
            }
            parity=curr;
        }

        return max({odd,even,alt});
        
    }
};