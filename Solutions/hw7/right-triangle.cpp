#include "right-triangle.hpp"

// TODO: Fill in these functions.

bool RightTriangle::Shift(int delta_x, int delta_y) {
    int new_ra_x = ra_point.GetX() + delta_x;
    int new_ra_y = ra_point.GetY() + delta_y;
    int new_second_point_y = new_ra_y + this->y_offset;
    int new_third_point_x = new_ra_x + this->x_offset;
    if (new_ra_x < 0 || new_ra_y < 0) {
        return false;
    }
    if (new_third_point_x < 0 || new_second_point_y < 0) {
        return false;
    }
    ra_point.SetXY(new_ra_x, new_ra_y);
    return true;
}

bool RightTriangle::DoubleSize() {
    int ra_x = ra_point.GetX();
    int ra_y = ra_point.GetY();
    int new_second_point_y = ra_y + 2 * this->y_offset;
    int new_third_point_x = ra_x + 2 * this->x_offset;
    if (new_third_point_x < 0 || new_second_point_y < 0) {
        return false;
    }
    this->x_offset *= 2;
    this->y_offset *= 2;
    return true;
}

bool RightTriangle::Rotate() {
    int ra_x = ra_point.GetX();
    int ra_y = ra_point.GetY();
    int new_second_point_y = ra_y - this->x_offset;
    int new_third_point_x = ra_x + this->y_offset;
    if (new_third_point_x < 0 || new_second_point_y < 0) {
        return false;
    }
    int backup_x_offset = this->x_offset;
    this->x_offset = this->y_offset;
    this->y_offset = -backup_x_offset;
    return true;
}
