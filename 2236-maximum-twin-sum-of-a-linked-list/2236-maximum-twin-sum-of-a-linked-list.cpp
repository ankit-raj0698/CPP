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

    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        
        ListNode* front = head->next;
        ListNode* newhead = reverseList(front);

        front -> next = head;
        head -> next = nullptr;

        return newhead;
    }

    int pairSum(ListNode* head) {

        ListNode* mid = findMid(head);
        ListNode* temp = reverseList(mid->next);
        mid->next = nullptr;

        ListNode* curr = head;
        ListNode* tempcurr = temp;

        int maxi = 0;

        while(curr && tempcurr){
            int sum = curr->val + tempcurr->val;
            maxi = max(maxi, sum);
            curr = curr->next;
            tempcurr = tempcurr->next;
        }
        return maxi;
    }
};