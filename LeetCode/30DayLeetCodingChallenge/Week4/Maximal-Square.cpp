// Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3312/
class Solution {
public:
    int customMin(int num1 , int num2 , int num3) {
        return min(num1,min(num2,num3)) ;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size() ;
        if (h == 0)
            return 0 ;
        int w = matrix[0].size() ;
        vector<vector<int>> sumMatrix(h,vector<int>(w)) ;

        for (int i = 0 ; i < h ; i++) {
            sumMatrix[i][0] = matrix[i][0] - '0';
        }

        for (int j = 0 ; j < w ; j++) {
            sumMatrix[0][j] = matrix[0][j] - '0';
        }

        int result = 0 ;

        for(int i = 1 ; i < h ; i++) {
            for (int j = 1 ; j < w ; j++) {
                if (matrix[i][j] - '0' == 1) {
                    sumMatrix[i][j] = customMin(sumMatrix[i][j-1],sumMatrix[i-1][j],sumMatrix[i-1][j-1]) + 1 ;
                }
                else {
                    sumMatrix[i][j] = 0 ;
                }
            }
        }

        for (int i = 0 ; i < h ; i++) {
            for (int j = 0 ; j < w ; j++) {
                if (sumMatrix[i][j] > result)
                    result = sumMatrix[i][j] ;
            }
        }

        return result * result ;
    }
};
