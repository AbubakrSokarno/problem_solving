// Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3300/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 1)
            return {0} ;

        vector<int> product_sum ;
        int tmp = 1 ;
        for(int i : nums) {
            tmp *= i ;
            product_sum.push_back(tmp);
        }

        tmp = 1 ;
        int ln = nums.size() ;
        for(int x = ln - 1 ; x >= 0 ; --x)  {
            if (x == 0)
                product_sum[x] =  tmp ;
            else
                product_sum[x] = product_sum[x-1] * tmp ;

            tmp = tmp * nums[x] ;
        }

        return product_sum ;
    }
};
