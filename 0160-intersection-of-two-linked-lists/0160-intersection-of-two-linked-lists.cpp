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

        int p = countNodes(headA);
        int q = countNodes(headB);

        ListNode* currA = headA;
        ListNode* currB = headB;

        if(p > q){
            int n = p - q;
            while(currA && n--)
                currA = currA->next;
        }
        else{
            int n = q - p;
            while(currB && n--)
                currB = currB->next;
        }
        
        while(currA && currB){
            if(currA == currB)
                return currA;
            
            currA = currA->next;
            currB = currB->next;
        }

        return NULL;
    }
};