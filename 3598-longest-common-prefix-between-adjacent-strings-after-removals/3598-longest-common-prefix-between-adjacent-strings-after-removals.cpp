class Solution {
public:
    int help(string &temp1,string &temp2){
        int i=0,j=0;
        int cnt=0;
        while(i<temp1.size() && j<temp2.size()){
            if(temp1[i]==temp2[j]){
                cnt++;
                i++;
                j++;
            }
            else break;
        }
        return cnt;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        if(n==1) return {0};
        if(n==2) return {0,0};
        vector<int>a(n);
        for(int i=0;i+1<n;i++){
            string temp1=words[i];
            string temp2=words[i+1];
            a[i]=help(temp1,temp2);
        }
        vector<int>pre_max(n);
        vector<int>suf_max(n);
        pre_max[0]=a[0];
        for(int i=1;i<n;i++){
            pre_max[i]=max(pre_max[i-1],a[i]);
        }
        suf_max[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            suf_max[i]=max(suf_max[i+1],a[i]);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
           
            if(i==0){
                ans[i]=suf_max[i+1];
            }
            else if(i==n-1){
                ans[i]=pre_max[i-2];
            }
            else{
                ans[i]=suf_max[i+1];
                if(i>=2) ans[i]=max(ans[i],pre_max[i-2]);
                
                int temp=help(words[i-1],words[i+1]);
                ans[i]=max(ans[i],temp);
            }
            
        }
        return ans;
    }
};