//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
  
    Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
    
    Node* reverseBetween(int m, int n, Node* head) {
        // code here
        if (!head || m == n) return head;

    // Dummy node to simplify edge cases
    Node* dummy = new Node(0);
    dummy->next = head;

    // Step 1: Find the node just before position m (prev) and node at position m (start)
    Node* prev = dummy;
    for (int i = 1; i < m; ++i) {
        prev = prev->next;
    }
    
    // Start node is at position m
    Node* start = prev->next;
    // End node is at position n
    Node* end = start;
    for (int i = m; i < n; ++i) {
        end = end->next;
    }

    // Step 2: Unlink the portion from the rest of the list
    Node* nextPart = end->next; // Keep track of the node after position n
    end->next = nullptr; // Break the link at position n

    // Step 3: Reverse the portion from m to n
    Node* reversedList = reverseList(start);

    // Step 4: Reattach the reversed portion back to the main list
    prev->next = reversedList; // Attach the previous part to the new head
    start->next = nextPart; // Attach the reversed tail to the remaining part

    // Return the new head of the list
    return dummy->next;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int a = arr[0], b = arr[1];

        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        if (arr2.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr2[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr2.size(); ++i) {
            data = arr2[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node* newhead = ob.reverseBetween(a, b, head);
        printList(newhead);
    }
    return 0;
}

// } Driver Code Ends