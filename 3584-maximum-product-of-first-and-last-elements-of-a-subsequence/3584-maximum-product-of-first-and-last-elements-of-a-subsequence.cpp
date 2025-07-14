#define ll long long 
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<ll> pos(n);
        vector<ll> neg(n);
        if (m == 1) {
            ll maxi = 0;
            for (int i = 0; i < n; i++) {
                ll ans = 1LL * nums[i] * nums[i];
                maxi = max(ans, maxi);
            }
            return maxi;
        }

        pos[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            pos[i] = max(pos[i + 1], (ll)nums[i]);
        }

        neg[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            neg[i] = min(neg[i + 1], (ll)nums[i]);
        }

        ll maxi = LLONG_MIN;
        for (int i = 0; i <= n - m; i++) {
            ll ans;
            if (nums[i] > 0) {
                ans = 1LL * nums[i] * pos[i + m - 1];  

            } else {
                ans = 1LL * nums[i] * neg[i + m - 1];
            }
            maxi = max(ans, maxi);
        }

        return maxi;
    }
};