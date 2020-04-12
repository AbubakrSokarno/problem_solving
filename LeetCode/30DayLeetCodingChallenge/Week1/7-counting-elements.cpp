/**
 * Problem Link :-
 * - https://leetcode.com/problems/counting-elements/
 * */
 
class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int,int> mp ;

        for(int item : arr) {
            if(mp.count(item) > 0){
                mp[item]++ ;
            }
            else {
                mp[item] = 1 ;
            }
        }

        int result = 0 ;

        for( auto i : mp ) {
            if(mp.count(i.first+1) > 0) {
                result += mp[i.first];
            }
        }

        return result ;
    }
};
