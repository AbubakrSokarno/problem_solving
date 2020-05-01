// problem link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions() ;
        int h = dimensions[0] ;
        int w = dimensions[1] ;
        int least = INT_MAX ;
        for (int i = 0 ; i < h ; i++) {
            int p1 = 0 ;
            int p2 = w - 1 ;

            while (p1 <= p2) {
                int mid = p1 + (p2 - p1) / 2 ;
                int midVal = binaryMatrix.get(i,mid) ;
                if (midVal == 1){
                    p2 = mid - 1 ;
                    if (mid < least)
                        least = mid ;
                }
                else {
                    p1 = mid + 1 ;
                }
            }
        }

        return (least == INT_MAX) ? -1 : least ;
    }
};
