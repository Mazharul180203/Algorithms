/// given tree is BST or not

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node (int v) {
        data = v;
        left = right = nullptr;
    }

};

bool inorder(Node* root, int &mini){

    if (root == nullptr) return true;

    if (!inorder(root->left, mini)) return false;
    if (root->data <= mini) return false;
    mini = root->data;
    cout<<root->data<<" ";

    return inorder(root->right, mini);

}

bool isBST(Node* root){
    int mini = INT_MIN;

    return inorder(root,mini);

}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(5);

    if(isBST(root))cout<<"True";
    else cout<<"False";
}
