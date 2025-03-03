class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(),part=-1;
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;--i)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                part=i+1;
                break;
            }
            ++mp[nums[i]];
        }
        if(part==-1)
            return 0;
        //cout<<part<<"\n";
        return(part%3==0)?part/3:part/3+1;
    }
};