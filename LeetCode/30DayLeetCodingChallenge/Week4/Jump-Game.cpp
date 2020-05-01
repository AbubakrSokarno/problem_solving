// Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3310/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int maxReach = 0 ;
        for (int i = 0 ; i < sz ; i++) {
            if (i > maxReach)
                return false ;
            maxReach = max(maxReach, i + nums[i]) ;
        }
        return true ;
    }
};
