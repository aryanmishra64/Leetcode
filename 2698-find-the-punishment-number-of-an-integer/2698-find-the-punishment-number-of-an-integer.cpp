class Solution {
public:
bool check(int i,int currsum,int num,string s){
    if(i==s.length()){
        return currsum==num;
    }
    if(currsum>num){
        return false;
    }
    bool possible =false;

    for(int j=i;j<s.length();j++){
        string sub=s.substr(i,j-i+1);

        int val=stoi(sub);

        possible = possible || check(j+1,currsum+val,num,s);

        if(possible==true){
            return true;
        }

    }
    return possible;
}
    int punishmentNumber(int n) {
        
        int ans=0;

        for(int num=1;num<=n;num++){
            int sq=num*num;

            string s=to_string(sq);
            if(check(0,0,num,s)==true){
                ans+=sq;
            }
        }
        return ans;

        
    }
};