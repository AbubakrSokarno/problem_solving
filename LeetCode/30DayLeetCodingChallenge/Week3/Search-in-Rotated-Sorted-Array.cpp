// Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3304/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1 ;
        int p1 = 0 ;
        int p2 = nums.size() - 1 ;
        int first = nums[0] ;
        while (p1 <= p2) {
            int pivot = p1 + (p2-p1) / 2 ;
            int val = nums[pivot] ;
            if (target == val) {
                return pivot ;
            }
            bool is_val_big = val >= first ;
            bool is_target_big = target >= first;
            if (is_val_big == is_target_big) {
                if (val < target)
                    p1 = pivot + 1 ;
                else
                    p2 = pivot - 1 ;
            } else {
                if (is_val_big)
                    p1 = pivot + 1 ;
                else
                    p2 = pivot - 1 ;
            }
        }
        return -1 ;
    }
};
