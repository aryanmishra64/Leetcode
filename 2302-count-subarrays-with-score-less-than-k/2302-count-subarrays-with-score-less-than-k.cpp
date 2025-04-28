class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int n=nums.size();

        

       
        long long sum=0;
        long long res=0;
        int mul=0;
       

        int i=0;
        int j=0;
        while(j<n){
            sum+=(nums[j]);
            mul=j-i+1;

            while((sum*mul)>=k){

                sum-=nums[i];
                mul--;
                i++;


                

            }
            if((sum*mul)<k){
                res+=j-i+1;
            }
            j++;
        }
        return res;
    }
};