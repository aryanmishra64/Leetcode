class Solution {
public:
    long long minArraySum(vector<int>& A, int k) {
        vector<long long> dp(k, LLONG_MAX);
        dp[0] = 0;
        long long res = 0;
        for (int a : A) {
            res += a;
            res = dp[res % k] = min(dp[res % k], res);
        }
        return res;
    }
};