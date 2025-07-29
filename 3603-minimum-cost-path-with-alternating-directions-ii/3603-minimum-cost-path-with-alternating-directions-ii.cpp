class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}};

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        
        priority_queue<
            pair<long long,pair<int,pair<int,int>>>,
            vector<pair<long long,pair<int,pair<int,int>>>>,
            greater<pair<long long,pair<int,pair<int,int>>>>>
        pq;

        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2,LLONG_MAX)));

        long long startCost=1*1;
        dist[0][0][1]=startCost;
        pq.push({startCost,{1,{0,0}}});

        while (!pq.empty()) {
            auto [cost,state] = pq.top();
            pq.pop();
            auto [time,coord]=state;
            int x=coord.first, y=coord.second;
            int parity=time%2;

          
            if (cost>dist[x][y][parity]) continue;
            if (x==m-1 && y==n-1) return cost;

            if (parity==1) { 
                for (auto& d:dir) {
                    int nx=x+d[0], ny=y+d[1];
                    if (nx>=m||ny>=n) continue;

                    long long entryCost = 1LL*(nx + 1)*(ny + 1);
                    long long newCost = cost + entryCost;

                    if (newCost < dist[nx][ny][0]) {
                        dist[nx][ny][0]=newCost;
                        pq.push({newCost, {time + 1, {nx, ny}}});
                    }
                }
            } else { // even second 
                long long wait = waitCost[x][y];
                long long newCost = cost + wait;

                if (newCost < dist[x][y][1]) {
                    dist[x][y][1] = newCost;
                    pq.push({newCost, {time + 1, {x, y}}});
                }
            }
        }

        return -1;
    }
};