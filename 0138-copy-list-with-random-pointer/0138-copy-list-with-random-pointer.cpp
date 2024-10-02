/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
            return head;

        // insert copy of node beside each node
        Node* curr = head;
        while(curr){
            Node* currNext = curr->next;
            // A ---> B
            // A ---> x ---> B
            Node* newNode = new Node(curr->val);
            curr->next = newNode;
            newNode->next = currNext;

            curr = currNext;
        }

        // copy the random pointer
        curr = head;
        while(curr){
            if(curr->random == nullptr){
                curr->next->random = nullptr;
            }
            else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // seperate the two lists
        curr = head;
        Node* newhead = head->next;
        Node* newCurr = newhead;

        while(curr && newCurr){
            curr->next = curr->next == nullptr ? nullptr: curr->next->next;
            newCurr->next = newCurr->next == nullptr ? nullptr: newCurr->next->next;

            curr = curr->next;
            newCurr = newCurr->next;

        }
        return newhead;
    }
};