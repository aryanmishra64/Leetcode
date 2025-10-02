class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int full=numBottles;
        int exchange=numExchange;

        int empty=0;
        int drunk=0;
        empty=full;
        full=0;
        
        drunk+=numBottles;

        while((full!=0) || (empty>=exchange) ){

            while(empty>=exchange){
                empty=empty-exchange;
                exchange++;
                full++;
            }
            drunk+=full;
            empty+=full;
            full=0;
        }
        return drunk;
        
    }
};