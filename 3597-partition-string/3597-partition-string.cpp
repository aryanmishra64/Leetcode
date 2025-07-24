class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.length();

        unordered_map<string,int>mpp;

        vector<string>ans;
        string temp="";

        for(int i=0;i<n;i++){

             temp+=s[i];

            if(mpp.size()==0 || mpp.find(temp)==mpp.end()){
                ans.push_back(temp);
                mpp[temp]++;
                temp="";
            }            

        }
        return ans;
        

    }
};