class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        int n=limit;
        vector<int>ans;
        
        unordered_map<int,int>ballmap;
        unordered_map<int,int>colormap;

        for(auto it:queries){
            int x=it[0];
            int y=it[1];

           if(ballmap.count(x)){
            int prev=ballmap[x];
            colormap[prev]--;

            if(colormap[prev]==0){
                colormap.erase(prev);
            }

           }
           ballmap[x]=y;
           colormap[y]++;

           ans.push_back(colormap.size());

            

           




        }
        return ans;
    }
};