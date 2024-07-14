//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    // make sure head1->data < head2->data
    if(head1->data > head2->data)
        return sortedMerge(head2, head1);
        
    // handle empty list   
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    
    // handle case when there is only one node in first list
    if(head1->next == NULL){
        head1->next = head2;
        return head1;
    }
        
    
    Node* curr1 = head1;
    Node* next1 = curr1->next;
    Node* curr2 = head2;
    Node* next2 = nullptr;
    
    
    // since we are comparing next1 data so use it in while condition
    
    while(next1 && curr2){
        // curr1->data <= curr2->data <= next1->data
        if((curr1->data <= curr2->data) && (curr2->data <= next1->data)){
            next2 = curr2->next;
            
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;
            // when we are left with only one node in first list, handle it
            if(next1 == nullptr){
                curr1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}  