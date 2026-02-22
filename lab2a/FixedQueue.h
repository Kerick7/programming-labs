#ifndef CPP_FIXEDQUEUE_H
#define CPP_FIXEDQUEUE_H

#include "Queue.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

class FixedQueue : public Queue {
private:
    Rectangle data[100];
    int head, tail, size;
public:
    FixedQueue() {
        head = 0;
        tail = 0;
        size = 0;
    }

    ~FixedQueue() {}

    void enqueue(Rectangle rect) {
        if (size == 100) {
            cout<<"Queue is full";
            return;
        }
        else {
            data[tail] = rect;
            tail = (tail + 1) % 100;
            size++;
        }
    }
    Rectangle dequeue() {
        if (size == 0) {
            cout<<"Queue is empty";
            return Rectangle();
        }
        else {
            Rectangle temp = data[head];
            head = (head + 1) % 100;
            size--;
            return temp;
        }
    }
    bool is_empty() {
        return size == 0;
    }
};

#endif //CPP_FIXEDQUEUE_H