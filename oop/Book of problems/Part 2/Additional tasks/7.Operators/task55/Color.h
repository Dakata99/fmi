#pragma once

enum ColorValue
{
    COLOR_UNDERFLOW = -1, RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET, NUMBER_OF_COLORS, COLOR_OVERFLOW
};

class Color
{
private:
    ColorValue myColVal;
public:
    Color();
    Color(ColorValue);

    friend bool operator==(const Color&, const Color&);
    friend bool operator!=(const Color&, const Color&);
    friend bool operator>(const Color&, const Color&);
    friend bool operator<(const Color&, const Color&);
    friend bool operator>=(const Color&, const Color&);
    friend bool operator<=(const Color&, const Color&);

    Color& operator++();
    Color operator++(int);

    Color& operator--();
    Color operator--(int);

    operator int()const;

    void print()const;
};
