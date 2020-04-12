/**
*    Problem Link :-
*    - https://leetcode.com/problems/single-number/
*    - It is solved using bitwise operator XOR and with another solution using brute force algorithm
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0 ;
        for(int i : nums){
            x ^= i ;
        }
        return x ;
        /*map<int,int> mp ;
        int result = 0 ;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            map<int,int>::iterator it = mp.find(nums[i]);

            if (it != mp.end()) {
                it->second++;
            }
            else {
                mp.insert(std::make_pair(nums[i], 1));
            }
        }

        for (auto const& e: mp) {
            if(e.second == 1){
                result = e.first ;
            }
        }

        return result ;*/
    }
};
