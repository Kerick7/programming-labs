#ifndef UNTITLED4_EXPRESSIONTREE_H
#define UNTITLED4_EXPRESSIONTREE_H

#include <iostream>
#include <string>

using namespace std;

struct ExprNode {
    string value;
    ExprNode* left;
    ExprNode* right;

    ExprNode(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class ExpressionTree {
public:
    ExprNode* root;
    ExpressionTree() { root = nullptr; }
    double evaluate(ExprNode* node) {
        if (node == nullptr) return 0;

        if (node->left == nullptr && node->right == nullptr) {
            return stod(node->value);
        }
        double leftVal = evaluate(node->left);
        double rightVal = evaluate(node->right);
        if (node->value == "+") return leftVal + rightVal;
        if (node->value == "-") return leftVal - rightVal;
        if (node->value == "*") return leftVal * rightVal;
        if (node->value == "/") {
            if (rightVal == 0) {
                cout << "Error. Dividing by 0!" << endl;
                return 0;
            }
            return leftVal / rightVal;
        }
        return 0;
    }

    void printMath(ExprNode* node) {
        if (node == nullptr) return;
        bool isOperator = (node->left != nullptr && node->right != nullptr);
        if (isOperator) cout << "(";
        printMath(node->left);
        cout << node->value;
        printMath(node->right);

        if (isOperator) cout << ")";
    }
};

#endif //UNTITLED4_EXPRESSIONTREE_H