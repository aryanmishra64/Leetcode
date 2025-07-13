class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freqPrev, freqNext;

        // Step 1: Count all frequencies initially in freqNext
        for (int num : nums) {
            freqNext[num]++;
        }

        long long result = 0;
        int n = nums.size();

        for (int j = 0; j < n; ++j) {
            int val = nums[j];

            // Remove current element from freqNext since it's now in the middle
            freqNext[val]--;

            int twice = val * 2;
            long long left = freqPrev[twice];  // how many i's before j
            long long right = freqNext[twice]; // how many k's after j

            result = (result + (left * right) % MOD) % MOD;

            // Add current element to freqPrev
            freqPrev[val]++;
        }

        return result;
    }
};
