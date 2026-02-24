#ifndef CPP_RECTANGLE_H
#define CPP_RECTANGLE_H

struct Rectangle {
    double x1, y1, x2, y2;
    Rectangle(double x1, double y1, double x2, double y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    Rectangle() {
        x1 = 0; y1 = 0; x2 = 0; y2 = 0;
    }
};

#endif //CPP_RECTANGLE_H