#ifndef CPP_VECTORQUEUE_H
#define CPP_VECTORQUEUE_H

#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;

class VectorQueue : public Queue{
private:
    vector<Rectangle> data;
public:
    ~VectorQueue(){}

    void enqueue(Rectangle rect) {
        data.push_back(rect);
    }

    Rectangle dequeue() {
        if (data.empty()) {
            cout << "VectorQueue is empty" << endl;
            return Rectangle();
        }
        else {
            Rectangle temp = data[0];
            data.erase(data.begin());
            return temp;
        }
    }

    bool is_empty() {
        return data.empty();
    }
};

#endif //CPP_VECTORQUEUE_H