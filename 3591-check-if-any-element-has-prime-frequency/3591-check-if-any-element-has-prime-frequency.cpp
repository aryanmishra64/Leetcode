class Solution {
public:
    bool isPri(int val){
        if(val==2) return true;
        if(val<=1) return false;


        int cnt=0;

        for(int i=1;i<=val;i++){
            if(val%i==0){
                cnt++;
            }
        }
        if(cnt==2){
            return true;
        }
        else {
            return false;
        }
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it:mpp){
            int freq=it.second;
            if(isPri(freq)){
                return true;
            }
        }
        return false;
    }
};