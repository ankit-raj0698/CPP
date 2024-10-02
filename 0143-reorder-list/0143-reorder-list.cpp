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
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        
        ListNode* front = head->next;
        ListNode* newhead = reverseList(front);

        front -> next = head;
        head -> next = nullptr;

        return newhead;
    }
    void reorderList(ListNode* head) {

        ListNode* mid = findMid(head);
        ListNode* temp = reverseList(mid->next);
        mid->next = nullptr;

        ListNode* curr = head;
        ListNode* tempcurr = temp;

        while(curr && tempcurr){
            ListNode* currNext = curr->next;
            ListNode* tempNext = tempcurr->next;

            curr->next = tempcurr;
            tempcurr->next = currNext;

            curr = currNext;
            tempcurr = tempNext;
        }
        
    }
};