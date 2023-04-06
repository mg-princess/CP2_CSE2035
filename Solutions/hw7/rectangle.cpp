#include "rectangle.hpp"

// TODO: Fill in these functions.

bool Rectangle::Shift(int delta_x, int delta_y) {
    int new_left_up_x = left_up.GetX() + delta_x;
    int new_left_up_y = left_up.GetY() + delta_y;
    int new_right_low_x = right_low.GetX() + delta_x;
    int new_right_low_y = right_low.GetY() + delta_y;
    if (new_left_up_x < 0 || new_left_up_y < 0) {
        return false;
    }
    if (new_right_low_x < 0 || new_right_low_y < 0) {
        return false;
    }
    left_up.SetXY(new_left_up_x, new_left_up_y);
    right_low.SetXY(new_right_low_x, new_right_low_y);
    return true;
}

bool Rectangle::DoubleSize() {
    int left_up_x = left_up.GetX();
    int left_up_y = left_up.GetY();
    int right_low_x = right_low.GetX();
    int right_low_y = right_low.GetY();
    int width = right_low_x - left_up_x;
    int height = right_low_y - left_up_y;
    int new_right_low_x = right_low_x + width;
    int new_right_low_y = right_low_y + height;
    // new_right_low_* are always valid, no need to check.
    right_low.SetXY(new_right_low_x, new_right_low_y);
    return true;
}

bool Rectangle::Rotate() {
    int left_up_x = left_up.GetX();
    int left_up_y = left_up.GetY();
    int right_low_x = right_low.GetX();
    int right_low_y = right_low.GetY();
    int width = right_low_x - left_up_x;
    int height = right_low_y - left_up_y;
    int new_left_up_x = left_up_x;
    int new_left_up_y = left_up_y - width;
    int new_right_low_x = left_up_x + height;
    int new_right_low_y = left_up_y;
    if (new_left_up_x < 0 || new_left_up_y < 0) {
        return false;
    }
    // new_right_low_* are always valid, no need to check.
    left_up.SetXY(new_left_up_x, new_left_up_y);
    right_low.SetXY(new_right_low_x, new_right_low_y);
    return true;
}
