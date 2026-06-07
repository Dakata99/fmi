#include "Color.h"

Color::Color()
{
    myColVal = COLOR_UNDERFLOW;
}
Color::Color(ColorValue val)
{
    myColVal = val;
}

bool operator==(const Color& first, const Color& second)
{
    return first.myColVal == second.myColVal;
}
bool operator!=(const Color& first, const Color& second)
{
    return !(first.myColVal == second.myColVal);
}
bool operator>(const Color& first, const Color& second)
{
    return first.myColVal > second.myColVal;
}
bool operator<(const Color& first, const Color& second)
{
    return first.myColVal < second.myColVal;
}
bool operator>=(const Color& first, const Color& second)
{
    return first.myColVal >= second.myColVal;
}
bool operator<=(const Color& first, const Color& second)
{
    return first.myColVal <= second.myColVal;
}

Color& Color::operator++()
{
    int temp = (int)myColVal;
    if (temp >= -1 && temp < 8)
    {
        temp++;
        myColVal = (ColorValue)temp;
        return *this;
    }
    
    myColVal = COLOR_OVERFLOW;
    return *this;
}
Color Color::operator++(int num)
{
    int temp = (int)myColVal;
    if (temp >= -1 && temp < 8)
    {
        temp++;
        myColVal = (ColorValue)temp;
        return *this;
    }
    
    myColVal = COLOR_OVERFLOW;
    return *this;
}

Color& Color::operator--()
{
    int temp = (int)myColVal;
    if (temp >= 0 && temp <= 8)
    {
        temp--;
        myColVal = (ColorValue)temp;

        return *this;
    }
    
    myColVal = COLOR_UNDERFLOW;
    return *this;
}
Color Color::operator--(int num)
{
    int temp = (int)myColVal;
    if (temp >= 0 && temp <= 8)
    {
        temp--;
        myColVal = (ColorValue)temp;

        return *this;
    }
    
    myColVal = COLOR_UNDERFLOW;
    return *this;
}

Color::operator int()const
{
    return int(myColVal);
}

void Color::print()const
{
    switch (myColVal)
    {
    case -1: std::cout << "COLOR_UNDERFLOW\n"; break;
    case 0: std::cout << "RED\n"; break;
    case 1: std::cout << "ORANGE\n"; break;
    case 2: std::cout << "YELLOW\n"; break;
    case 3: std::cout << "GREEN\n"; break;
    case 4: std::cout << "BLUE\n"; break;
    case 5: std::cout << "INDIGO\n"; break;
    case 6: std::cout << "VIOLET\n"; break;
    case 7: std::cout << "NUMBER_OF_COLORS\n"; break;
    case 8: std::cout << "COLOR_OVERFLOW\n"; break;    
    default: std::cout << "Invalid\n"; break;
    }
}