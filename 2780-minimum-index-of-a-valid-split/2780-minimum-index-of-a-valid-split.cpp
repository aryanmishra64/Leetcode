class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        // Count occurrences of each element
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int maxi = 0, dom = 0;
        for (auto it : mpp) {
            if (it.second > maxi) {
                maxi = it.second;
                dom = it.first;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dom) {
                cnt++;
            }

            int curr = i + 1; // Size of the left subarray
            if (cnt * 2 > curr) { // Check if dominant in left subarray
                int remaining = maxi - cnt;
                int rightSize = n - (i + 1); // Size of the right subarray
                if (remaining * 2 > rightSize) { // Check if dominant in right subarray
                    return i;
                }
            }
        }

        return -1; // No valid split found
    }
};
