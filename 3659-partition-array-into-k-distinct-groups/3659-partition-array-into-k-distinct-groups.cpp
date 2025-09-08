class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        int groups = n / k;

        unordered_map<int,int> freq;
        int maxFreq = 0;
        for (int x : nums) {
            maxFreq = max(maxFreq, ++freq[x]);
            if (maxFreq > groups) return false;
        }
        return true;
    }
};
