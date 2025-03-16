class Solution {
public:
    typedef long long ll;

    bool isPossible(vector<int>& ranks,ll mid, int cars){
        ll cnt=0;

        for(int i=0;i<ranks.size();i++){
            cnt+=sqrt(mid/ranks[i]);
        }
        return cnt>=cars;

    }

    
    long long repairCars(vector<int>& ranks, int cars) {
        
        ll res=-1;
        ll left=1;
        int n=ranks.size();
        ll maxi=*max_element(begin(ranks), end(ranks));
        ll right=1LL*maxi*cars*cars;

        while(left<=right){
            ll mid=(left+right)/2;

            if(isPossible(ranks,mid,cars)){
                res=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }

        }
        return res;
    }
};