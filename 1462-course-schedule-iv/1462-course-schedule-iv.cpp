class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        unordered_map<int,unordered_set<int>>mpp;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                mpp[it].insert(node);

                for(auto &pre:mpp[node]){
                    mpp[it].insert(pre);
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        int Q=queries.size();

        vector<bool>result(Q,false);

        for(int i=0;i<Q;i++){
            int src=queries[i][0];
            int dst=queries[i][1];

            bool reach=mpp[dst].contains(src);
            result[i]=reach;
        }
        return result;
    }
};