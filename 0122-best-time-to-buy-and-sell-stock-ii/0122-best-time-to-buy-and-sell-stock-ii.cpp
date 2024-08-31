class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<long> ahead(2,0), cur(2,0);

   
    ahead[0] = ahead[1] = 0;

    

   
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit=0;
             if (buy == 1) { 
                profit = max(0 + ahead[1], prices[ind] + ahead[0]);
            }

            else  { 
                profit = max(0 + ahead[0], -prices[ind] + ahead[1]);
            }

           
            cur[buy] = profit;
        }
        ahead=cur;
    }

   
    return ahead[0];
    }
};