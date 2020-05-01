/**
* Problem Link :
*  - https://leetcode.com/problems/contiguous-array/
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0 ;
        int n = nums.size() ;
        int pref = 0 ;
        unordered_map<int,int> mp ;
        mp[0] = 0;
        for(int i = 0 ; i < n ; i++) {
            pref += (nums[i] == 0 ? -1 : 1) ;
            auto it = mp.find(pref) ;
            if (it != mp.end()) {
                result = max(result,i + 1 - mp[pref]);
            }
            else {
                mp[pref] = i + 1 ;
            }
        }
        return result ;
    }
};
