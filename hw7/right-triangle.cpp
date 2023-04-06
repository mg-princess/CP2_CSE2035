#include "right-triangle.hpp"

// TODO: Fill in these functions.

bool RightTriangle::Shift(int delta_x, int delta_y) {
    if(ra_point.GetX() + delta_x < 0 || ra_point.GetY() + delta_y < 0)
        return false;
    ra_point.SetXY(ra_point.GetX() + delta_x, ra_point.GetY() + delta_y);
    return true;
}

bool RightTriangle::DoubleSize() {
    if(ra_point.GetX() + x_offset*2 < 0 || ra_point.GetY() + y_offset*2 < 0)
        return false;
    x_offset *= 2;
    y_offset *= 2;
    return true;
}

bool RightTriangle::Rotate() {
    if(ra_point.GetX() + y_offset < 0 || ra_point.GetY() + x_offset*(-1) < 0)
        return false;
    int x = x_offset;
    x_offset = y_offset;
    y_offset = x*(-1);
    return true;
}
