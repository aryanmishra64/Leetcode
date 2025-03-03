class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = INT_MIN, cnt = 0;
        for(int i=0; i<n; i++){
            int lower = nums[i] - k;
            int upper = nums[i] + k;

            if(prev<lower){
                prev = lower; cnt++;
            }
            else if(prev < upper){
                prev++; cnt++;
            }
        }
        return cnt;
    }
};