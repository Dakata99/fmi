#include "Boolean.h"

Boolean Boolean::operator&&(const Boolean& other)
{
    Bool temp = boo == TRUE && other.boo == TRUE? TRUE :FALSE;
    return Boolean(temp);
}
Boolean Boolean::operator||(const Boolean& other)
{
    Bool temp = boo == TRUE || other.boo == TRUE? TRUE : FALSE;
    return Boolean(temp);
}
Boolean Boolean::operator!(void)
{
    Bool temp = boo == TRUE? FALSE : TRUE;
    return Boolean(temp);
}

void Boolean::print()const
{
    if (boo == TRUE)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE\n";
    
}