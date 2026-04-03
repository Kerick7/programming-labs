/*
* Лабораторна робота №4 (Дерева)
 * Обраний варіант (шлях по блоках):
 * Блок 0: N-арне дерево з довільною кількістю дітей (Core)
 * Блок 1: Додавання елемента за шляхом (Core, Provides: PATH)
 * Блок 2: Вивід дерева з використанням відступів (Core)
 * Блок 3: Видалення елемента за шляхом (Core, Requires: PATH)
 * Блок 4: Бінарне дерево пошуку (додавання менших наліво, інших направо) (Core)
 * Блок 5: Послідовне подання на основі прямого порядку
 * Блок 6: Дерево для подання арифметичних виразів
 */
#include <iostream>
#include "Tree.h"
#include "BinaryTree.h"
#include "ExpressionTree.h"

using namespace std;

void runDemoMode() {
    cout << "\n=== DEMO MODE ===" << endl;

    cout << "\n[Block 0-3] N-ary tree:" << endl;
    Tree nTree;
    nTree.addByPath(100, {});
    nTree.addByPath(10, {});
    nTree.addByPath(20, {});
    nTree.addByPath(11, {0});
    nTree.printTree();
    cout << "Deleting subtree by way {0}..." << endl;
    nTree.removeByPath({0});
    nTree.printTree();

    cout << "\n[Block 4-5] Binary tree:" << endl;
    BinaryTree bTree;
    bTree.insert(50);
    bTree.insert(30);
    bTree.insert(70);
    bTree.insert(20);
    bTree.insert(40);
    bTree.printTree();

    cout << "Pre-order: ";
    vector<int> preOrder = bTree.getPreOrderTraversal();
    for (int val : preOrder) cout << val << " ";
    cout << endl;

    cout << "\n[Block 6] Arithmetic expression tree:" << endl;
    ExpressionTree exprTree;
    exprTree.root = new ExprNode("*");
    exprTree.root->left = new ExprNode("+");
    exprTree.root->right = new ExprNode("2");
    exprTree.root->left->left = new ExprNode("10");
    exprTree.root->left->right = new ExprNode("20");

    cout << "Expression: ";
    exprTree.printMath(exprTree.root);
    cout << "\n Result: " << exprTree.evaluate(exprTree.root) << endl;
    cout << "=============================\n" << endl;
}

void runInteractiveMode() {
    BinaryTree bTree;
    int choice = -1;

    cout << "\n=== Interactive mode (Binary tree) ===" << endl;
    while (choice != 0) {
        cout << "1. Add element" << endl;
        cout << "2. Print tree" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose action: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter number: ";
            cin >> val;
            bTree.insert(val);
            cout << "Added!" << endl;
        } else if (choice == 2) {
            bTree.printTree();
        }
    }
}

int main() {
    int mode;
    cout << "Choose programm mode:" << endl;
    cout << "1. Demo mode(auto)" << endl;
    cout << "2. Interactive mode(manual)" << endl;
    cout << "Your choice: ";
    cin >> mode;

    if (mode == 1) {
        runDemoMode();
    } else if (mode == 2) {
        runInteractiveMode();
    } else {
        cout << "Unknown mode" << endl;
    }

    return 0;
}