#pragma once

enum Bool
{
    FALSE, TRUE
};

class Boolean
{
private:
    Bool boo;
public:
    Boolean(Bool b = FALSE)
    {
        boo = b;
    }
    Boolean operator&&(const Boolean&);
    Boolean operator||(const Boolean&);
    Boolean operator!(void);

    void print()const;
};
