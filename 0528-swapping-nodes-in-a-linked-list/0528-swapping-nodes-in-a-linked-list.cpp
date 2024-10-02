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
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }

    ListNode* swapNodes(ListNode* head, int k) {

        if(!head)
            return head;
        
        int n = countNodes(head);
        ListNode* left = head;
        ListNode *right = head;

        int count = 1;
        while(count < k){
            left = left -> next;
            count++;
        }
            
        count = 1;
        while(count < n-k+1){
            count++;
            right = right->next;
        }

        swap(left->val, right->val);

        return head;
        
    }
};