class Solution {
public:
    void solve(int ind,int n,string &curr,vector<string>&res){

        if(ind==n){
            res.push_back(curr);
            return;
        }

        curr+='0';
        solve(ind+1,n,curr,res);
        curr.pop_back();

        curr+='1';
        solve(ind+1,n,curr,res);
        curr.pop_back();

    }


    string findDifferentBinaryString(vector<string>& nums) {
        
        string len=nums[0];

        int n=len.length();
        string curr;
        vector<string>res;

        solve(0,n,curr,res);

        string ans;

        unordered_map<string,int>mpp;

        for(auto it:nums){
            mpp[it]=1;
        }

        for(int i=0;i<res.size();i++){
            string val=res[i];
            if(mpp.find(val)==mpp.end()){
                ans=val;
                break;
            }
        }
        return ans;
    }
};