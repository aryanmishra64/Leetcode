class Solution {
public:
    bool canFormPairs(vector<int>& nums, int p, int mid) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 1; i < n; ) {
            if (nums[i] - nums[i - 1] <= mid) {
                count++;
                i += 2; // use both elements
            } else {
                i += 1; // skip only one
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFormPairs(nums, p, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
