// This is called a 'header guard'
#ifndef GRAPHICS_CLASS
#define GRAPHICS_CLASS

#include <iostream>

using std::cout;
using std::endl;

class Point {
private:
    int x;
    int y;
    bool fixed;
public:
    Point(int _x, int _y) : x(_x), y(_y), fixed(false) { }
    int GetX() { return x; }
    int GetY() { return y; }
    void SetX(int _x) { if (!fixed) x = _x; }
    void SetY(int _y) { if (!fixed) y = _y; }
    // Make the pointer unmovable.
    void Fix() { fixed = true; }
    // Make the pointer movable.
    void Unfix() { fixed = false; }
};

class Rectangle {
private:
    Point left_up;
    Point right_low;
public:
    // You can use 'member initializer' to call the constructor of 'Point'.
    Rectangle(int left_up_x, int left_up_y, int right_low_x, int right_low_y)
        : left_up(left_up_x, left_up_y), right_low(right_low_x, right_low_y)
    { }
    void Print() {
        int left_up_x = left_up.GetX();
        int left_up_y = left_up.GetY();
        int right_low_x = right_low.GetX();
        int right_low_y = right_low.GetY();
        cout << "Left-upper: (" << left_up_x << ", " << left_up_y << ")\n";
        cout << "Left-lower: (" << left_up_x << ", " << right_low_y << ")\n";
        cout << "Right-upper: (" << right_low_x << ", " << left_up_y << ")\n";
        cout << "Right-lower: (" << right_low_x << ", " << right_low_y << ")\n";
    }

    // Make the rectangle unmovable/unresizable.
    void Fix();
    // Make the rectangle movable/resizable.
    void Unfix();
    // Increase the height by 'delta'. Left-upper point should not change.
    void IncreaseHeight(int delta);
    // Increase the width by 'delta'. Left-upper point should not change.
    void IncreaseWidth(int delta);
    // Compute the size (area) of the rectangle.
    int Size();
};

#endif
