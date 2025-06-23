class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        int n=nums.size();
        vector<vector<int>>ans;
        vector<vector<int>>temp;

        sort(nums.begin(),nums.end());

        for(int i=1;i<n-1;i=i+3){
            vector<int>res;

            int first=nums[i];
            int prev=nums[i-1];
            int next=nums[i+1];

            if(abs(first-prev)>k || abs(first-next)>k || abs(prev-next)>k){
                return temp;
            }
            else{

                res.push_back(first);
                res.push_back(next);
                res.push_back(prev);

                ans.push_back(res);


            }
        }
        return ans;
        
    }
};