class Solution {
public:
    int gcd(int a , int b){
        if(b > a) return gcd(b,a);
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    int lcm(int a , int b){
        return (a*b)/gcd(a,b);
    }

    int maxLength(vector<int>& nums) {
        
        int maxi = INT_MAX;
        int n = nums.size(); int ans = 0; 
        for(int i = 0; i<n; i++){
            long long prod = 1; 
            long long gcdd = nums[i];
            long long lcmm = nums[i];
            for(int j = i; j<n; j++) {
                if(prod > maxi/nums[i]) break;
                prod *= nums[j];
                gcdd = gcd(gcdd , nums[j]);
                lcmm = lcm(lcmm , nums[j]);

                if(prod == lcmm*gcdd) ans = max(ans , j-i+1);
            }
        }
        return ans;
    }
};