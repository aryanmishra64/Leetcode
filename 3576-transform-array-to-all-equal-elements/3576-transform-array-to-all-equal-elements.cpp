class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        return check(nums, k, 1) || check(nums, k, -1);
    }

    bool check(vector<int> nums, int k, int tar) {
        int n = nums.size(), count = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != tar) {
                nums[i] *= -1;
                nums[i + 1] *= -1;
                count++;
                if (count > k) return false;
            }
        }

        return nums[n - 1] == tar;
    }
};