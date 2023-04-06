#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "right-triangle.hpp"

// I will fix these functions to test your class implementation

void MoveShapes(Shape ** shapes, int delta_x, int delta_y) {
    for (int i = 0; shapes[i] != NULL; i++)
        shapes[i]->Shift(delta_x, delta_y);
}

void doubleShapes(Shape ** shapes) {
    for (int i = 0; shapes[i] != NULL; i++)
        shapes[i]->DoubleSize();
}

void rotateShapes(Shape ** shapes) {
    for (int i = 0; shapes[i] != NULL; i++)
        shapes[i]->Rotate();
}

void printShapes(Shape ** shapes) {
    for (int i = 0; shapes[i] != NULL; i++) {
        shapes[i]->Print();
        std::cout << "================\n";
    }
}

void test() {
    Rectangle r(1, 1, 4, 3);
    RightTriangle t(5, 5, -3, -4);
    Shape* shapes[3];
    shapes[0] = &r;
    shapes[1] = &t;
    shapes[2] = NULL; // Let's use NULL pointer to indicate the end of array.
    //MoveShapes(shapes, 10, 20);
    printShapes(shapes);
    doubleShapes(shapes);
    printShapes(shapes);
    rotateShapes(shapes);
    printShapes(shapes);
    /* (Expected output)
       Left-upper: (11, 14)
       Left-lower: (11, 22)
       Right-upper: (15, 14)
       Right-lower: (15, 22)
       ================
       Point with right-angle: (15, 25)
       Second point: (15, 19)
       Third point: (23, 25)
    */
}

int main() {
    test();
    return 0;
}
