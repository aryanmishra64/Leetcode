class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=baskets.size();
        vector<int>hash(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((baskets[j]>=fruits[i]) && hash[j]!=1 ){
                    hash[j]=1;
                    break;
                }
            }


        }
        int cnt=0;
        for(int i=0;i<m;i++){
            if(hash[i]==0){
                cnt++;
            }
        }
        return cnt;
    }
};