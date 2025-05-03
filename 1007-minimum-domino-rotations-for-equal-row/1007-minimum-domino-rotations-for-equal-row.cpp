class Solution {
public:

    int solve(vector<int>& tops, vector<int>& bottoms,int val){

        int n=tops.size();
        int swaptop=0;
        int swapbot=0;

        for(int i=0;i<n;i++){

            if(tops[i]!=val && bottoms[i]!=val){
                return -1;
            }
            else if(tops[i]!=val){
                swaptop++;
            }
            else if(bottoms[i]!=val){
                swapbot++;

            }
        }
        return min(swaptop,swapbot);

    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int n=tops.size();
        int res=INT_MAX
        ;

        for(int val=1;val<=6;val++){
            int swaps=solve(tops,bottoms,val);

            if(swaps!=-1){
                res=min(res,swaps);
            }
        }
        return res == INT_MAX ? -1 : res;
        
    }
};