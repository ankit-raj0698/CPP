/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode* front = head->next;
        ListNode* newhead = reverseList(front);

        front->next = head;
        head->next = NULL;

        return newhead;
    }

    ListNode* removeNodes(ListNode* head) {

        ListNode* newhead = reverseList(head);
        ListNode* curr = newhead;
        int maxi = curr->val;

        while(curr){
            ListNode* front = curr->next;
            if(front && front->val < maxi){
                curr->next = front->next;
            }
            else{
                maxi = max(maxi, front ? front->val : maxi);
                curr = curr->next;
            }
        }
        return reverseList(newhead);;
    }
};