#include "rectangle.hpp"

// TODO: Fill in these functions.

bool Rectangle::Shift(int delta_x, int delta_y) {
    if(left_up.GetX() + delta_x < 0 || left_up.GetY() + delta_y < 0)
        return false;
    
    left_up.SetXY(left_up.GetX() + delta_x, left_up.GetY() + delta_y);
    right_low.SetXY(right_low.GetX() + delta_x, right_low.GetY() + delta_y);
    return true;
}

bool Rectangle::DoubleSize() {
    int width = right_low.GetX() - left_up.GetX();
    int height = right_low.GetY() - left_up.GetY();
    right_low.SetXY(right_low.GetX() + width, right_low.GetY() + height);
    return true;
}

bool Rectangle::Rotate() {
    int width = right_low.GetX() - left_up.GetX();
    int height = right_low.GetY() - left_up.GetY();

    if(left_up.GetY() - width < 0) 
        return false;

    right_low.SetXY(left_up.GetX() + height, left_up.GetY());
    left_up.SetXY(left_up.GetX(), left_up.GetY() - width);
    return true;
}
