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
Node* buildBalancedTree(vector<int>& vv, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(vv[mid]);
    root->left = buildBalancedTree(vv, start, mid - 1);
    root->right = buildBalancedTree(vv, mid + 1, end);
}

void storeInorder(Node* root, vector<int>& vv) {

    if (root == nullptr) return;

    storeInorder(root->left, vv);
    vv.push_back(root->data);
    storeInorder(root->right,vv);
}

Node* blanceBST(Node* root) {
    vector<int> vv;

    storeInorder(root,vv);

    return buildBalancedTree(vv, 0, vv.size() - 1);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(15);
    root->right->right = new Node(20);

    Node* balancedRoot = blanceBST(root);
    inorder(balancedRoot);
}
