#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    vector<TreeNode*> children;
    TreeNode(int data) { this->data = data; }
};

class Tree {
private:
    TreeNode* root;

    void printHelper(TreeNode* node, int level) {
        if (node == nullptr) return;
        for (int i = 0; i < level; i++) cout << "  ";
        cout << "- " << node->data << endl;
        for (int i = 0; i < node->children.size(); i++) {
            printHelper(node->children[i], level + 1);
        }
    }

public:
    Tree() { root = nullptr; }

    void addByPath(int value, const vector<int>& path) {
        if (root == nullptr) {
            root = new TreeNode(value);
            return;
        }
        TreeNode* current = root;
        for (int i = 0; i < path.size(); i++) {
            int idx = path[i];
            if (idx < 0 || idx >= current->children.size()) {
                cout << "Wrong way!" << endl;
                return;
            }
            current = current->children[idx];
        }
        current->children.push_back(new TreeNode(value));
    }

    void printTree() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "--- N-ary tree ---" << endl;
        printHelper(root, 0);
        cout << "---------------------" << endl;
    }

    TreeNode* removeByPath(const vector<int>& path) {
        if (root == nullptr) return nullptr;
        if (path.empty()) {
            TreeNode* removedNode = root;
            root = nullptr;
            return removedNode;
        }
        TreeNode* current = root;
        for (int i = 0; i < path.size() - 1; i++) {
            int idx = path[i];
            if (idx < 0 || idx >= current->children.size()) {
                cout << "Wrong way!" << endl;
                return nullptr;
            }
            current = current->children[idx];
        }
        int targetIdx = path.back();
        if (targetIdx < 0 || targetIdx >= current->children.size()) {
            cout << "Wrong way!" << endl;
            return nullptr;
        }
        TreeNode* removedNode = current->children[targetIdx];
        current->children.erase(current->children.begin() + targetIdx);
        return removedNode;
    }
};

#endif // TREE_H