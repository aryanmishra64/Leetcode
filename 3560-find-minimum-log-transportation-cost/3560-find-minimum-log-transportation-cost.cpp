class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {

        if(n<=k && m<=k ){
            return 0;
        }
        long long cost=0;
        long long rem=0;

        if(n>k){
            rem+=n-k;

        }
        if(m>k){
            rem+=m-k;
        }

        cost=rem*k;
        return cost;
        
    }
};