class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        long long ans = 0;
        while (left < right) {
            right--;
            ans += nums[right];
            left++;
            right--;
        }
        return ans;
    }
};