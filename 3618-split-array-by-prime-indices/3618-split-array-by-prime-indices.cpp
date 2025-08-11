class Solution {
public:

    bool isPrime(long long num){

        if(num<=1){
            return false;
        }

        if(num==2){
            return true;
        }

        if(num%2==0){
            return false;
        }

        for(int i=3;i*i<=num;i+=2){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>a;
        vector<long long>b;

        for(int i=0;i<n;i++){
            if(isPrime(i)){
                a.push_back(nums[i]);
            }
            else {
                b.push_back(nums[i]);
            }
        }
        long long sum1=0;
        for(int i=0;i<a.size();i++){
            sum1+=a[i];
        }
        long long sum2=0;
        for(int i=0;i<b.size();i++){
            sum2+=b[i];
        }
        long long ans=abs(sum1-sum2);

        return ans;

    }
};