/**
 * Problem Link :-
 * - https://leetcode.com/problems/middle-of-the-linked-list
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* tmp = head ;
        int nodeLength = 1 ;
        while (tmp->next != NULL) {
            tmp = tmp->next ;
            nodeLength++ ; 
        }
        int mid = ( nodeLength / 2 ) + 1 ;
        int i = 0 ;
        ListNode* answer = head ; 
        while(answer != NULL) {
            if(i + 1 == mid) {
                return answer; 
            }
            i++;
            answer = answer->next ; 
        }
        return NULL ; 
    }
};
