#include <iostream>
#include "Rectangle.h"
#include "Queue.h"
#include "FixedQueue.h"
#include "VectorQueue.h"
#include "ListQueue.h"
#include <ctime>
using namespace std;

int main() {
    int mode;
    cout<<"Select mode: "<<endl<<"1.Interactive (manual) mode"<<endl<<"2.Demo (automatic) mode"<<endl<<"3.Benchmark (speed test)"<<endl;
    cin>>mode;
    switch (mode) {
        case 1:{
            int type;
            Queue* var = nullptr;
            cout<<"Select type of queue: "<<endl<<"1.VectorQueue"<<endl<<"2.FixedQueue"<<endl<<"3.ListQueue"<<endl;
            cin>>type;
            switch (type) {
                case 1:
                    var = new VectorQueue();
                    break;
                case 2:
                    var = new FixedQueue();
                    break;
                case 3:
                    var = new ListQueue();
                    break;
                default:
                    cout<<"Unknown type"<<endl;
                    return 1;
            }
            bool isRunning = true;
            while(isRunning) {
                int com;
                cout<<"Select command: "<<endl<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.Is Empty"<<endl<<"4.Exit"<<endl;
                cin>>com;
                switch (com) {
                    case 0:
                        isRunning = false;
                        break;
                    case 1: {
                        double x1, y1, x2, y2;
                        cout<<"Enter coordinates of rectangle: "<<endl;
                        cin>>x1>>y1>>x2>>y2;
                        Rectangle rect(x1, y1, x2, y2);
                        var->enqueue(rect);
                        break;
                    }
                    case 2:
                        if (var->is_empty()) {
                            cout<<"Queue is empty"<<endl;
                        }
                        else {
                            Rectangle rect = var->dequeue();
                            cout<<"Removed element: "<<rect.x1<<" "<<rect.y1<<" "<<rect.x2<<" "<<rect.y2<<endl;
                        }
                        break;
                    case 3:
                        if (var->is_empty()) {
                            cout<<"Queue is empty"<<endl;
                        }
                        else {
                            cout<<"Queue is not empty"<<endl;
                        }
                        break;
                }
            }
            delete var;
            cout<<"Interactive mode finished"<<endl;
            break;
        }
        case 2: {
            cout<<"---DEMO MODE STARTED---"<<endl;
            Queue* var = new ListQueue();
            cout<<"Created ListQueue"<<endl;
            cout<<"Adding rectangle (10,10,20,20)..."<<endl;
            Rectangle rect1(10, 10, 20, 20);
            var->enqueue(rect1);
            cout<<"Adding rectangle (5,5,15,15)..."<<endl;
            Rectangle rect2(5, 5, 15, 15);
            var->enqueue(rect2);
            cout<<"Checking if empty..."<<endl;
            cout<<var->is_empty()<<endl;
            cout<<"Removing element..."<<endl;
            Rectangle r = var->dequeue();
            cout<<"Removed rectangle has coordinates: "<<r.x1<<" "<<r.y1<<" "<<r.x2<<" "<<r.y2<<endl;
            cout<<"Checking if empty again..."<<endl;
            cout<<var->is_empty()<<endl;
            delete var;
            cout<<"---DEMO MODE FINISHED---"<<endl;
        }
            break;
        case 3: {
            int N;
            cout<<"Enter amount of operation for test: "<<endl;
            cin>>N;
            unsigned int start, end, result;
            cout<<"Testing VectorQueue..."<<endl;
            Queue* v1 = new VectorQueue();
            start = clock();
            for (int i = 0; i < N; i++) {
                v1->enqueue(Rectangle());
            }
            for (int i = 0; i < N; i++) {
                v1->dequeue();
            }
            end = clock();
            result = end - start;
            cout<<"VectorQueue time: "<<result<<" ticks"<<endl;
            delete v1;

            cout<<"Testing ListQueue..."<<endl;
            Queue* v2 = new ListQueue();
            start = clock();
            for (int i = 0; i < N; i++) {
                v2->enqueue(Rectangle());
            }
            for (int i = 0; i < N; i++) {
                v2->dequeue();
            }
            end = clock();
            result = end - start;
            cout<<"ListQueue time: "<<result<<" ticks"<<endl;
            delete v2;

            cout<<"Testing FixedQueue..."<<endl;
            if (N>100) {
                cout<<"FixedQueue skipped, N must be <100"<<endl;
            }
            else {
                Queue* v3 = new FixedQueue();
                start = clock();
                for (int i = 0; i < N; i++) {
                    v3->enqueue(Rectangle());
                }
                for (int i = 0; i < N; i++) {
                    v3->dequeue();
                }
                end = clock();
                result = end - start;
                cout<<"FixedQueue time: "<<result<<" ticks"<<endl;
                delete v3;
            }
        }
        break;
    }
    return 0;
}