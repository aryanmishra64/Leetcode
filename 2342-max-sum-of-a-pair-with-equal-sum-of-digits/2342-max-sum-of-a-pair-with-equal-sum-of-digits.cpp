class Solution {
public:
    int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {

        // Extract the last digit
        int last = n % 10;

        // Add last digit to sum
        sum += last;

        // Remove the last digit
        n /= 10;
    }
    return sum;
}


    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,int>mpp;
        int result=-1;

        for(int i=0;i<nums.size();i++){

            int cal=sumOfDigits(nums[i]);

            if(mpp.count(cal)){
                result=max(result,nums[i]+mpp[cal]);

            }
            mpp[cal]=max(mpp[cal],nums[i]);
        }

        return result;

    }
};