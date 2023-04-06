#include <cstdio>
#include "graphics.hpp"

// TODO: Fill in these functions. Check the comments in graphics.hpp file.

void Rectangle::Fix()
{
    left_up.Fix();
    right_low.Fix();
}

void Rectangle::Unfix()
{
    left_up.Unfix();
    right_low.Unfix();
}

void Rectangle::IncreaseHeight(int delta)
{
    if (delta < 0)
        return;
    right_low.SetY(right_low.GetY() + delta);
}

void Rectangle::IncreaseWidth(int delta)
{
    if (delta < 0)
        return;
    right_low.SetX(right_low.GetX() + delta);
}

int Rectangle::Size()
{
    return (right_low.GetY() - left_up.GetY()) * (right_low.GetX() - left_up.GetX());
}
