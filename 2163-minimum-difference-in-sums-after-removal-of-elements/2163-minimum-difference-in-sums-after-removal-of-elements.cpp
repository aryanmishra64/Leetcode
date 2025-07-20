class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;
        vector<long long>leftsum(N,0);
        vector<long long>rightsum(N,0);

        priority_queue<int>pq;
        long long sum=0;

        for(int i=0;i<2*n;i++){
            pq.push(nums[i]);
            sum+=nums[i];

            if(pq.size()>n){
                sum-=pq.top();
                pq.pop();
            }
            leftsum[i]=sum;
        }

        priority_queue<int,vector<int>,greater<int>>pqq;

        long long minsum=0;

        for(int i=N-1;i>=n;i--){
            pqq.push(nums[i]);
            minsum+=nums[i];

            if(pqq.size()>n){
                minsum-=pqq.top();
                pqq.pop();
            }
            rightsum[i]=minsum;
        }

        long long res=LLONG_MAX;

        for(int i=n-1;i<=2*n-1;i++){
            res=min(res,leftsum[i]-rightsum[i+1]);
        }
        return res;



    }
};