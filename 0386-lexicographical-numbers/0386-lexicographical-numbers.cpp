class Solution {
public:
    void solve(int num,int limit,vector<int>&ans)
    {
        if(num>limit){
            return;
        }
        ans.push_back(num);

        for(int add=0;add<=9;add++){
           int val=(num*10)+add;
            if(val>limit){
                return;
            }
            solve(val,limit,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int>ans;

        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }

        return ans;
    }
};