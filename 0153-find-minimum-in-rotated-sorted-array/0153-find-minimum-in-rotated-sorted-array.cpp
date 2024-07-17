class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
		//if size of array is one
        if(n==1)
            return nums[0];
        
        //if array is sorted then first element is smallest
        if(nums[0] < nums[n-1])
            return nums[0];
        
        int start = 0;
        int end = n-1;
        
        int ans = INT_MAX;
        while(start <= end){
            
            int mid = (start + end) / 2;
			
			//if mid is in first part of array
            if(nums[mid] >= nums[0])
                start = mid +1;
            
            else
            {
                ans = min(ans , nums[mid]);
                end = mid - 1;
            }
        }
        return ans;
    }
};