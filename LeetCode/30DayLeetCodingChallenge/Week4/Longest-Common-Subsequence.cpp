//Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3311/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
	    vector<vector<int>> matrix(m + 1, std::vector<int>(n + 1, 0));

        for(int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (text1[i] == text2[j]) {
                    matrix[i+1][j+1] = matrix[i][j] + 1 ;
                } else {
                    matrix[i+1][j+1] = max(matrix[i][j+1],matrix[i+1][j]) ;
                }
            }
        }

        return matrix[m][n] ;
    }
};
