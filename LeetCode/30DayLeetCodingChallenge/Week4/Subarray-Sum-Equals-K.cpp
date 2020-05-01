// Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3307/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prev_sum ;
        int sum = 0 ;
        int res = 0 ;
        for (int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i] ;

            if (sum == k) {
                res++ ;
            }

            if (prev_sum.find(sum - k) != prev_sum.end()) {
                res += prev_sum[sum-k] ;
            }

            prev_sum[sum]++ ;
        }

        return res ;
    }
};
