#include "Points.h"

Points::Points(const size_t num)
{
    current = 0;
    max = num;
    points = new Point2[max];
}
Points::Points(const Points& other)
{
    current = other.current;
    max = other.max;
    points = other.points;
}
Points::~Points()
{
    delete[]points;
}

Points& Points::operator=(const Points& other)
{
    if (this != &other)
    {
        delete[]points;
        current = other.current;
        max = other.max;
        points = other.points;
    }
    return *this;
}

Points intersection(Points& first, Points& second)
{
    Points temp;
    temp.max = first.max > second.max? second.max : first.max;
    temp.points = new Point2[temp.max];
    for (size_t i = 0; i < first.current; i++)
    {
        for (size_t j = 0; j < second.current; j++)
        {
            if (!temp.isIn(first.points[i]))
            {
                size_t counter = first.getTimes(first.points[i]);
                size_t counter2 = second.getTimes(first.points[i]);
                if (counter >= counter2)
                {
                    while (counter2 > 0)
                    {
                        temp.add(first.points[i]);
                        counter2--;
                    }
                }
                else
                {
                    while (counter > 0)
                    {
                        temp.add(first.points[i]);
                        counter--;
                    }
                }
            }
        }
    }
    
    return temp;
}

bool Points::isIn(const Point2& p)const
{
    for (size_t i = 0; i < current; i++)
    {
        if (points[i] == p)
        {
            return true;
        }
    }
    return false;
}
size_t Points::getTimes(const Point2& p)
{
    size_t counter = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (points[i] == p)
        {
            counter++;
        }
    }
    return counter;
}
void Points::setSize(const size_t size)
{
    max = size;
}
void Points::add(const Point2& p)
{
    if (current >= max)
    {
        max += 3;
        Point2* temp = new Point2[max];
        for (size_t i = 0; i < current; i++)
        {
            temp[i] = points[i];
        }
        delete[]points;
        points = new Point2[max];
        for (size_t i = 0; i < current; i++)
        {
            temp[i] = points[i];
        }
        delete[]temp;
    }
    points[current++] = p;
}

void Points::print()const
{
    std::cout << "Points are:\n";
    for (size_t i = 0; i < current; i++)
    {
        points[i].print();
    }
    std::cout << std::endl;
}