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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode* front = head->next;
        ListNode* newhead = reverseList(front);

        front->next = head;
        head->next = NULL;

        return newhead;
    }

    bool isPalindrome(ListNode* head) {

        if(!head || !head->next)
            return true;
        
        ListNode* mid = findMid(head);
        mid->next = reverseList(mid->next);

        ListNode* head1 = head;
        ListNode* head2 = mid->next;

        while(head1 && head2){
            if(head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        mid->next = reverseList(mid->next);
        return true;
    }
};