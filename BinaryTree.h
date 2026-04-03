#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>

using namespace std;

struct BTNode {
    int data;
    BTNode* left;
    BTNode* right;
    BTNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    BTNode* root;
    BTNode* insertHelper(BTNode* node, int value) {
        if (node == nullptr) return new BTNode(value);
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }
    void printHelper(BTNode* node, int level) {
        if (node == nullptr) return;
        for (int i = 0; i < level; i++) cout << "  ";
        cout << "- " << node->data << endl;
        printHelper(node->left, level + 1);
        printHelper(node->right, level + 1);
    }
    void preOrderHelper(BTNode* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->data);
        preOrderHelper(node->left, result);
        preOrderHelper(node->right, result);
    }
public:
    BinaryTree() { root = nullptr; }
    void insert(int value) {
        root = insertHelper(root, value);
    }
    void printTree() {
        if (root == nullptr) {
            cout << "Binary tree is empty!" << endl;
            return;
        }
        cout << "--- Binary tree ---" << endl;
        printHelper(root, 0);
        cout << "-----------------------------" << endl;
    }
    vector<int> getPreOrderTraversal() {
        vector<int> result;
        preOrderHelper(root, result);
        return result;
    }
};

#endif // BINARYTREE_H