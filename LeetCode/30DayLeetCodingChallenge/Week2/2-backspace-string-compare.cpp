/**
 * Problem Link :-
 * - https://leetcode.com/problems/backspace-string-compare/
 * */
 
class Solution {
public:
    bool backspaceCompareV2(string S, string T) {
        stack<char> s1 ;
        stack<char> s2 ; 
        for(auto a : S) {
            if(a=='#') { 
                if(! s1.empty()) {
                    s1.pop(); 
                }
            }
            else {
                s1.push(a) ; 
            }
        }
        
        for(auto a : T) {
            if(a=='#') { 
                if(! s2.empty()) {
                    s2.pop(); 
                }
            }
            else {
                s2.push(a) ; 
            }
        }
        
        bool result = true ;
        while(! s1.empty() && ! s2.empty()) {
            if(s1.top() != s2.top()) {
                result = false ;
                break ;
            }
            s1.pop();
            s2.pop();
        }
        if (result && ! s1.empty() && s2.empty())
            result = false ;
        if (result && s1.empty() && !s2.empty())
            result = false ;
        
        return result ;
    } 
    
    string build (string s){ 
        stack<char> res ; 
        for(char a : s) {
            if(a=='#') { 
                if(! res.empty()) {
                    res.pop(); 
                }
            }
            else {
                res.push(a) ; 
            }
        }
        
        string ans = "" ;
        while(! res.empty()) {
            ans += res.top() ;
            res.pop() ;
        }
        return ans ;
    }

    bool backspaceCompare(string S, string T) {
        return build(S) == build(T) ;
    }
};
