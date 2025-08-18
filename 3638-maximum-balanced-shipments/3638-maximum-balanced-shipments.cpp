class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int cnt=0;

        for(int i=1;i<n;i++){
            if(weight[i]<weight[i-1]){
                cnt++;
                i++;
            }
        }
        return cnt;

    }
};