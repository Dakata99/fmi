#ifndef _DATE_H_
#define _DATE_H_

class Date
{
private:
    size_t day, month, year;
public:
//des/constructors
    Date(const size_t = 1, const size_t = 1, const size_t = 1999);
    Date(const Date&);
    Date& operator=(const Date&);

//func
    void print()const;
};

#endif