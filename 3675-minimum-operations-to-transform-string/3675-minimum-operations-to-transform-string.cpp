class Solution {
public:
    int minOperations(string s) {
        int n=s.length();

        int maxi=INT_MIN;

        for(char ch:s){
            int dis=abs(ch-'a');

           if(dis!=0) dis=26-dis;
            maxi=max(maxi,dis);
        }
        return maxi;
    }
};