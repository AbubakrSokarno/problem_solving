/**
*   Problem Link :-
*   - https://leetcode.com/problems/happy-number/
*/

class Solution {
public:

    int f (int n) {
        int sum = 0 ;
        while(n) {
            int digit = n%10 ;
            n = n / 10 ;
            sum += digit * digit ;
        }
        return sum ;
    }

    bool isHappy(int n) {
        unordered_set<int> visited ;
        while(true) {
            if (n == 1) {
                return true ;
            }
            n = f(n) ;
            if(visited.count(n)){
                return false ;
            }
            visited.insert(n);
        }
    }

};
