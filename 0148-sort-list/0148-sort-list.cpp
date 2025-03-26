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

    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;

    }

    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* result = new ListNode(-1);
        ListNode* curr = result;

        while(first && second){
            if(first->val < second->val){
                curr->next = first;
                first = first->next;
            }
            else{
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }

        if(first != nullptr)
            curr->next = first;
        
        if(second != nullptr)
            curr->next = second;
        
        return result->next;
    }

    ListNode* sortList(ListNode* head) {
        // base case
        if(!head || !head -> next)
            return head;
        
        // find the middle node
        ListNode* mid = findmid(head);

        // divide list into 2 parts: left and right i.e. define heads for them
        ListNode* left = head;
        ListNode* right = mid ->next;
        mid->next = NULL; // last node of left points to null

        // sort left and right half
        left = sortList(left);
        right = sortList(right);

        // merge two sorted linked list and return result
        ListNode* result = merge(left, right);
        return result;
        
    }
};