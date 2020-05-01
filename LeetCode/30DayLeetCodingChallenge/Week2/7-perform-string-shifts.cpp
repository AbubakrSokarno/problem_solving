/**
* Problem Link :
*  - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3299/
*/
class Solution {
public:
    void leftrotate(string &s, int d)
    {
        reverse(s.begin(), s.begin()+d);
        reverse(s.begin()+d, s.end());
        reverse(s.begin(), s.end());
    }

    void rightrotate(string &s, int d)
    {
       leftrotate(s, s.length()-d);
    }

    string rotate (string s , int direction, int num_of_moves) {
        num_of_moves %= s.length() ;
        if (direction == 1) { // right shift
            rightrotate( s,num_of_moves ) ;
        } else { // left shift
            leftrotate( s, num_of_moves ) ;
        }
        return s ;
    }

    string stringShift(string s, vector<vector<int>>& shift) {
        int total_left_shifts = 0 ;
        int total_right_shifts = 0 ;
        for (auto i : shift) {
            if (i[0] == 1)
                total_right_shifts+=i[1] ;
            else
                total_left_shifts+=i[1] ;
        }
        int direction ;
        int number_of_moves = 0 ;
        if (total_right_shifts > total_left_shifts) {
            direction = 1 ;
            number_of_moves = total_right_shifts - total_left_shifts ;
        }
        else if (total_right_shifts < total_left_shifts) {
            direction = 0 ;
            number_of_moves = total_left_shifts - total_right_shifts ;
        }
        else { // the string still as it is , because left shifts = right shifts
            return s ;
        }
        return rotate(s,direction,number_of_moves) ;
    }
};
