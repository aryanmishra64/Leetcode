class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        
        int n=arr.size();
        long long ans1=0;

        for(int i=0;i<n;i++){
            int diff=abs(arr[i]-brr[i]);
            ans1+=diff;

        }

        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());

        long long ans2=0;

        for(int i=0;i<n;i++){
            int diff=abs(arr[i]-brr[i]);
            ans2+=diff;
        }
        ans2+=k;

        long long res=min(ans1,ans2);

        return res;
    }
};