class Solution {
public:
    int solve(vector<int>&arr){
        int n=arr.size();
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int dist=mpp.size();

        unordered_map<int,int>count;
        int ans=0;

        int i=0;
        int j=0;
        while(j<n){
            count[arr[j]]++;

            while(count.size()>=dist){
                count[arr[i]]--;
                if(count[arr[i]]==0){
                    count.erase(arr[i]);
                }
                i++;
            }

            if(count.size()<dist){
                ans+=j-i+1;
            }
            j++;

            
            
        }
        return ans;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int total =(n*(n+1))/2;

        return total - solve(nums);
    }
};