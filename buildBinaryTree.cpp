// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
        
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

node* buildTree(node* root){
    int data;
    cout<< "enter data"<<endl;
    cin>>data;
    
    root = new node(data);
    if(data == -1)
        return NULL;
    cout<< "enter root->left data"<<endl;
    root->left = buildTree(root->left);
    cout<< "enter root->right data"<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            node* front = q.front();
            q.pop();
            if(level % 2 == 0)
                cout<< front->data<<" ";
            
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        if(level % 2 == 0)
            cout<<endl;
        level++;
    }
}

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}


int main() {
    node* root = NULL;
    root = buildTree(root);
    
    levelorder(root);

    return 0;
}
