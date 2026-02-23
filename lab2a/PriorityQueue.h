#ifndef CPP_PRIORITYQUEUE_H
#define CPP_PRIORITYQUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct PNode {
    string data;
    int priority;
    PNode* next;

    PNode(string d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    PNode* head;
public:
    PriorityQueue() {
        head = nullptr;
    }
    bool is_empty() {
        return head == nullptr;
    }
    void dequeue() {
        if (is_empty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        else {
            PNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        if (is_empty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        else {
            PNode* current = head;
            while (current != nullptr) {
                cout<<current->data<<" "<<current->priority<<endl;
                current = current->next;
            }
        }
    }
    ~PriorityQueue() {
        while (!is_empty()) {
            dequeue();
        }
    }
    void enqueue(string d, int p) {
        PNode* newNode = new PNode(d, p);
        if (is_empty() || p < head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            PNode* current = head;
            while (current->next != nullptr && current->next->priority <= p) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
};

#endif