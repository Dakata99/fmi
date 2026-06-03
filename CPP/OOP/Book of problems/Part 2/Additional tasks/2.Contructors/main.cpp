#include <iostream>

class Imperial
{
private:
    int theYards, theFeet, theInches;
public:
    Imperial(int aYard = 0, int aFoot = 0, int aInch = 0):theYards(aYard), theFeet(aFoot), theInches(aInch){}
    void add(const Imperial& other)
    {
        theYards += other.theYards;
        theFeet += other.theFeet;
        theInches += other.theInches;
    }
    void mul(int factor)
    {
        theYards *= factor;
        theFeet *= factor;
        theInches *= factor;
    }

    int yards()const
    {
        return theYards;
    }
    int feet()const
    {
        return theFeet;
    }
    int inches()const
    {
        return theInches;
    }
    void print()const
    {
        std::cout << theYards << " " << theFeet << " " << theInches << std::endl;
    }
};

int main()
{
    Imperial i(1, 2, 3);
    i.add(Imperial());
    i.print();

    i.mul(1);
    i.print();


    return 0;
}