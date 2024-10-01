/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // count no. of nodes in both the list
    // find the difference in count
    // move the head of longer list untill both lists are of same count
    // now compare both list nodes one by one
    // if they are pointing to same address then return that node
    // otherwise return null
    int countNodes(ListNode* head){
        int count = 0;
        ListNode* curr = head;
        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int countA = countNodes(headA);
        int countB = countNodes(headB);

        int diff = 0;
        if(countA > countB){
            diff = countA - countB;
            while(diff--){
                headA = headA->next;
            }
        }
        else if(countA < countB){
            diff = countB - countA;
            while(diff--){
                headB = headB->next;
            }
        }

        while(headA && headB){
            if(headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};