class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>group(n,0);
        int curr=0;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                curr++;
            }
            group[i]=curr;
        }
        vector<bool>res;
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            if(group[u]==group[v]){
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};