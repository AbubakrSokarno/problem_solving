/**
 * Problem Link :-
 * - https://leetcode.com/problems/group-anagrams/
 * */
 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp ;
        vector<vector<string>> result ;

        for(string str : strs) {
            string item = str;
            sort(str.begin(), str.end());
            mp[str].push_back(item);
        }

        for( auto item : mp ){
            result.push_back(item.second);
        }
        return result;
    }
};
