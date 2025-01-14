class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1,0);
        vector<int>ans1;

        int ans=0;

        for(int i=0;i<n;i++){
             freq[A[i]]++;
            freq[B[i]]++;
            int a=freq[A[i]];
            int b=freq[B[i]];

            if(a==2 && b==2 && A[i]!=B[i] ){
                ans+=2;
            }
            else if(a==2 || b==2){
                ans+=1;
            }
            ans1.push_back(ans);

        }
        return ans1;
        
    }
};