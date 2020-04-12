/**
*   Problem Link :-
*   - https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros_counter = 0 ;
        for(int x = 0 ; x < nums.size() ; x++) {
            if(nums[x] == 0){
                zeros_counter++;
                nums.erase(nums.begin() + x);
                if(nums.empty())
                    break ;
                x--;
            }
        }
        for(int i = 0 ; i < zeros_counter ; i++) nums.push_back(0) ;
    }
};
