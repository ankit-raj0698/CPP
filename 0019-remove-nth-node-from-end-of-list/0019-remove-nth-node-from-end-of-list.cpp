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

    int countNodes(ListNode* head){
        
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    ListNode* approach1(ListNode* head, int n){
        if(head == nullptr)
            return head;
        
        int size = countNodes(head);
        int pos = size - n;

        if(pos == 0)
            return head->next;
        
        int count = 1;
        ListNode* curr = head;
        while(curr && count < pos){
            curr = curr->next;
            count++;
        }
        curr -> next = curr->next->next;

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
         
        // return approach1(head, n);
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* left = dummy;
        ListNode* right = head;

        while(right && n--)
            right = right->next;

        while(right){
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;

        return dummy->next;
        
    }
};