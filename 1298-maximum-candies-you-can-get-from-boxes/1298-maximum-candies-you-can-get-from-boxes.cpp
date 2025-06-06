class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n=status.size();
        int ans=0;
        unordered_set<int>visited;
        unordered_set<int>foundboxes;
        queue<int>q;

        for(auto it:initialBoxes){
            foundboxes.insert(it);

            if(status[it]==1){
                q.push(it);
                visited.insert(it);
                ans+=candies[it];
            }
        }

        while(!q.empty()){
            int box=q.front();
            q.pop();

            for(auto it:containedBoxes[box]){
                foundboxes.insert(it);
                if(status[it]==1 && !visited.count(it)){
                    q.push(it);
                    visited.insert(it);
                    ans+=candies[it];
                }
            }
            for(auto key:keys[box]){
                
                status[key]=1;
                 if(foundboxes.count(key)  &&
                 
                  !visited.count(key)){
                    q.push(key);
                    visited.insert(key);
                    ans+=candies[key];
                }

            }

        }
        return ans;


 
    }
};