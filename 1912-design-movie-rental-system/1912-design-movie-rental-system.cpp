class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>>avail;//price,shop
    unordered_map<int,set<pair<int,int>>>movietoshop;//shp, price
    set<tuple<int,int,int>>rented;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto it:entries){
            int shop=it[0];
            int movie=it[1];
            int price=it[2];

            avail[movie].insert({price,shop});
            movietoshop[movie].insert({shop,price});
            

        }
    }
    
    vector<int> search(int movie) {

        int cnt=0;
        vector<int>res;

        if(avail.count(movie)){
            for(auto &[price,shop]:avail[movie]){
                res.push_back(shop);
                cnt++;
                if(cnt==5){
                    break;
                }
            }
        }
        return res;
        
    }
    
    void rent(int shop, int movie) {
        auto it=movietoshop[movie].lower_bound({shop,INT_MIN});
        int price=it->second;

        avail[movie].erase({price,shop});
        rented.insert({price,shop,movie});
        
    }
    
    void drop(int shop, int movie) {
        auto it=movietoshop[movie].lower_bound({shop,INT_MIN});
        int price=it->second;

        avail[movie].insert({price,shop});
         rented.erase({price,shop,movie});


        
    }
    
    vector<vector<int>> report() {

        vector<vector<int>>ans;
        int cnt=0;

        for(auto &[price,shop,movie]:rented){
            ans.push_back({shop,movie});
            cnt++;
            if(cnt==5){
                break;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */