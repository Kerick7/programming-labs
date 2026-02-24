#ifndef CPP_LISTQUEUE_H
#define CPP_LISTQUEUE_H

#include <iostream>
#include "Queue.h"
#include "Rectangle.h"
using namespace std;

struct Node {
    Rectangle value;
    Node* next;
};
class ListQueue : public Queue {
private:
    Node* head;
    Node* tail;
    int size;
public:
    ListQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    };
    ~ListQueue () {
        while (head != nullptr) {
            dequeue();
        }
    }
    void enqueue (Rectangle value) {
        Node* temp = new Node;
        temp->value = value;
        temp->next = nullptr;
        if (head == nullptr) {
            head = temp;
            tail = temp;
            size++;
        }
        else {
            tail->next = temp;
            tail = temp;
            size++;
        }
    }
    Rectangle dequeue () {
        if (head == nullptr) {
            cout << "Queue is empty";
            return Rectangle();
        }
        else {
            Rectangle temp = head->value;
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
            size --;
            if (head == nullptr) {
                tail = nullptr;
            }
            return temp;
        }
    }
    bool is_empty() {
        return size == 0;
    }
};

#endif //CPP_LISTQUEUE_H