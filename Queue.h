#ifndef CPP_QUEUE_H
#define CPP_QUEUE_H

#include "Rectangle.h"
class Queue {
public:
    virtual ~Queue() {}
    virtual void enqueue(Rectangle rect) = 0;
    virtual Rectangle dequeue() = 0;
    virtual bool isEmpty() = 0;
};

#endif //CPP_QUEUE_H