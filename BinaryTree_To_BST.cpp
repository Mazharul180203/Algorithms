/// Binary Tree to BST

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

void constructBST(Node* root, vector<int> vv, int& idx) {
    if (root == nullptr) return;

    constructBST(root->left, vv, idx);

    root->data = vv[index++];

    constructBST(root->right, vv, idx);
}

void inorder(Node* root, vector<int> &vv){

    if(root == nullptr) return;

    inorder(root->left,vv);
    vv.push_back(root->data);
    inorder(root->right,vv);
}

Node* binaryTreeToBST(Node* root){
    vector<int> vv;
    inorder(root,vv)

    sort(vv.begin(), vv.end());
    int idx = 0;

    constructBST(root,vv,idx);
}

int main() {
     Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(4);
    Node* ans = binaryTreeToBST(root);
    printInorder(ans)

}
