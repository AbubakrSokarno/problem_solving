/**
* Problem Link :
*  - https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 1 ; i < nums.size() ; i++) {
            if (nums[i] == nums[i-1]) {
                nums.erase(nums.begin() + i);
                i-- ;
            }
        }
        return nums.size() ;
    }
};
