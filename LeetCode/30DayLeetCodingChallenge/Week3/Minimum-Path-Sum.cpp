// Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3303/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int w = grid[0].size() ;
        int h = grid.size() ;
        vector<vector<int>> dp(h,vector<int>(w)) ;
        for (int i = 0 ; i < h ; i++) {
            for (int j = 0 ; j < w ; j++) {
                dp[i][j] += grid[i][j] ;
                if (i > 0 && j > 0) {
                    dp[i][j] += min(dp[i-1][j],dp[i][j-1]) ;
                } else if (i > 0) {
                    dp[i][j] += dp[i-1][j] ;
                } else if (j > 0) {
                    dp[i][j] += dp[i][j-1] ;
                }
            }
        }

        return dp[dp.size() - 1][dp[0].size() -1 ] ;
    }
};
