class Solution {
public:
    int find(int i,int j,vector<int>&arr){

        return *max_element(arr.begin()+i, arr.begin()+j+1);
    }
    int solve(int ind,int k,vector<int>& arr,vector<int>&dp){
        if(ind==arr.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int maxi=INT_MIN;


        for(int j=ind;j<arr.size();j++){
            int cost=0;
            
            if(j-ind+1<=k){
                 cost = find(ind,j,arr)*(j-ind+1)+solve(j+1,k,arr,dp);
                maxi=max(maxi,cost);


            }
        } 
        return dp[ind]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();

        vector<int>dp(n+1,-1);


        int ans=solve(0,k,arr,dp);
        return ans;
    }
};