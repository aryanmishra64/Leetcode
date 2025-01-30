class Solution {
public:
    void helper(vector<int>& nums,set<vector<int>>&st,int ind){
        if(ind==nums.size()){
            st.insert(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            helper(nums,st,ind+1);
            swap(nums[i],nums[ind]);
        }

    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        set<vector<int>>st;

        helper(nums,st,0);

        for(auto it:st){
            result.push_back(it);
        }
        return result;

    }
};