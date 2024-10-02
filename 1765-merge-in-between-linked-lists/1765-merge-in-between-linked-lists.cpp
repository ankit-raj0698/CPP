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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        // Pointer to traverse list1
        ListNode* curr1 = list1;

        // To keep track of current position in the list
        int count = 0;

        // Front will be used to find the b-th node in list1
        ListNode* front = list1;

        // Traverse the list until reaching the (a-1)-th node (node just before index a)
        while(curr1 && count < a - 1) {
            curr1 = curr1->next;
            front = front->next;
            count++;
        }

        // Traverse until reaching the b-th node in list1
        while(front && count < b) {
            front = front->next;
            count++;
        }

        // Connect the (a-1)-th node to the head of list2
        curr1->next = list2;

        // Traverse to the end of list2 to find the last node
        ListNode* curr2 = list2;
        while(curr2->next) {
            curr2 = curr2->next;
        }

        // Connect the last node of list2 to the node after the b-th node in list1
        curr2->next = front->next;

        // Return the modified list1
        return list1;
        
    }
};