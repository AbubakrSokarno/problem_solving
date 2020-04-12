/**
 * Problem Link :-
 * - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 , sum = 0 ; 
        for(int i = 1 ; i < prices.size() ; i++) {
            sum = prices[i] - prices[i-1] ;
            if(sum > 0)
                profit += sum ;
        }
        return profit ; 
    }
};
