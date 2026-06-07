#include <iostream>
#include <cstring>

class Calculator
{
private:
    char* expression;
public:
    void setExpr(const char* expr)
    {
        expression = new char[strlen(expr) + 1];
        strcpy(expression, expr);
    }
    bool valid()const
    {
        bool flag = false;
        for (size_t i = 0; i < strlen(expression); i++)
        {
            flag = 
            if (!(expression[i] >= '1' && expression[i] <= '9') || (expression[i] != '+', expression[i] != '-' || expression[i] != '*' || expression[i] != '/'))
            {
                return false;
            }
        }
        return true;
    }
    int calculate()const
    {
        for (size_t i = 0; i < strlen(expression); i++)
        {
            if (expression[i] >= '1' && expression[i] <= '9')
            {
                /* code */
            }
        }
    }
};

int main()
{
    Calculator c1;
    c1.setExpr("26/5+4");
    std::cout << std::boolalpha << c1.valid() << std::endl;

    return 0;
}