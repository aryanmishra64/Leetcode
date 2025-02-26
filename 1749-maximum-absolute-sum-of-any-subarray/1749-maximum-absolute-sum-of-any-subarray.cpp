class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, maxi = nums[0], n = nums.size();

        // Kadane's Algorithm for Maximum Subarray Sum
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
        }

        int newSum = 0, mini = INT_MAX;

        // Kadane's Algorithm for Minimum Subarray Sum
        for (int i = 0; i < n; i++) {
            newSum += nums[i];
            mini = min(mini, newSum);
            if (newSum > 0) newSum = 0;
        }

        // Return max of absolute values
        return max(maxi, abs(mini));
    }
};
