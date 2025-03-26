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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);

        ListNode* odd = dummy1;
        ListNode* even = dummy2;
        ListNode* curr = head;
        int cnt = 1;

        while(curr){
            if(cnt % 2 == 0){
                even->next = curr;
                even = curr;
            }
            else{
                odd->next = curr;
                odd = curr;
            }
            curr = curr->next;
            cnt++;
        }

        odd->next = dummy2->next;
        even->next = nullptr;
        return dummy1->next;
        
    }
};