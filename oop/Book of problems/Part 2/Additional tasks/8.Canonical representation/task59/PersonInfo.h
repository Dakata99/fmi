#pragma once

class PersonInfo
{
private:
    char* name;
    int age;
public:
    PersonInfo(const char* = "", int = 0);
    PersonInfo(const PersonInfo&);
    ~PersonInfo();
    PersonInfo& operator=(const PersonInfo&);

    void print()const;
};
