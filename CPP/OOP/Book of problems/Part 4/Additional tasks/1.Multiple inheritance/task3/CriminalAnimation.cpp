#include "CriminalAnimation.h"
#include <cstring>

//des/constructors
CriminalAnimation::CriminalAnimation(const char* name1, const size_t year1, const size_t dead, const char* name2, const size_t year2, const char* animator)
    :Criminal(name1, year1, dead), Animation(name2, year2, animator){}
CriminalAnimation::CriminalAnimation(const Criminal& c, const Animation& a):Criminal(c), Animation(a){}

//operators
CriminalAnimation& CriminalAnimation::operator=(const CriminalAnimation& other)
{
    if (this != &other)
    {
        Criminal::operator=(other);
        Animation::operator=(other);
    }
    return *this;
}
//getters

//setters

//funcs
void CriminalAnimation::print()const
{
    std::cout << "Criminal and animation movie with name: " << Criminal::getName() << " " << Animation::getName() << std::endl;
    //Criminal::print();
    //Animation::print();
}