/**
 * Problem Link :-
 * - https://leetcode.com/problems/last-stone-weight/
 * */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int sz = stones.size();
        if (sz == 1)
            return stones[0];
        while(true) {
            sort(stones.begin(),stones.end()) ; 
            int num1 = stones[sz - 2] ; 
            int num2 = stones[sz - 1] ;
            if (num1 > 0 && num2 > 0) { 
                if (num2 > num1) {
                    stones[sz - 1] = stones[sz - 1] - num1;
                    stones[sz - 2] = 0;
                } else {
                    stones[sz - 1] = 0;
                    stones[sz - 2] = 0;
                }
            }
            else {               
                return num2 ;    
            }
        }
        return 0 ;
    }
};
