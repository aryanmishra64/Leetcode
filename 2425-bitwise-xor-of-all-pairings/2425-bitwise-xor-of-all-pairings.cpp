class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        int m=nums2.size();

        int XOR=0;

        if(n%2!=0){
            for(auto it:nums2){
                XOR^=it;
            }

        }
        if(m%2!=0){
            for(auto it:nums1){
                XOR^=it;
            }
        }

        return XOR;
    }
};