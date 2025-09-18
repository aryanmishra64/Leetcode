class FoodRatings {
public:

    unordered_map<string,int>food_rating;
    unordered_map<string,set<pair<int,string>>>cusine_rating_food;
    unordered_map<string,string>food_cusine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();

        for(int i=0;i<n;i++){
            string food=foods[i];
            string cusine=cuisines[i];
            int rate=ratings[i];

            cusine_rating_food[cusine].insert({-rate,food});
            food_cusine[food]=cusine;
            food_rating[food]=rate;

        }
    }
    
    void changeRating(string food, int newRating) {
        
        string cusine=food_cusine[food];
        int oldrate=food_rating[food];

        food_rating[food]=newRating;

        cusine_rating_food[cusine].erase({-oldrate,food});
        cusine_rating_food[cusine].insert({-newRating,food});



    }
    
    string highestRated(string cuisine) {
        return begin(cusine_rating_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */