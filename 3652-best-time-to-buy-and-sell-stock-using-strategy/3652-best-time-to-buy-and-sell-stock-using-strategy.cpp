class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>prefix(n,0);

        prefix[0]=prices[0];
        vector<long long>orig(n,0);
        long long sum=0;

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+prices[i];


        }
        for(int i=0;i<n;i++){
            sum+=prices[i]*strategy[i];
            orig[i]=sum;
        }
        long long ans=orig[n-1];

        for(int i=k-1;i<n;i++){
            long long leftsum=0;
            long long rightsum=0;
            long long changesum=prefix[i]-prefix[i-(k/2)];

            if(i-k>=0){
                leftsum=orig[i-k];

            }

            rightsum=orig[n-1]-orig[i];

            ans=max(ans,leftsum+rightsum+changesum);

        }
        return ans;
    }
};