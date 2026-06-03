#include "Doctor.h"

size_t Doctor::currentPatient = 0;

//des/constrictors
    Doctor::Doctor(const char* name, const Date date, const size_t num):Person(name, date)
    {
        registered = num;
        pats = new Patient[registered];
    }
    Doctor::~Doctor()
    {
        delete[]pats;
    }

//operators

//funcs
    void Doctor::add(const Patient& pat)
    {
        if (registered >= 100)
        {
            std::cout << "Cannot add more patients to this doctor!" << std::endl;
            return;
        }
        else if (currentPatient == registered - 1)
        {
            registered++;
            Patient* temp = new Patient[registered];
            for (size_t i = 0; i < currentPatient; i++)
            {
                temp[i] = pats[i];
            }
            
            delete[]pats;
            pats = new Patient[registered];
            for (size_t i = 0; i < currentPatient; i++)
            {
                pats[i] = temp[i];
            }
            delete[]temp;
        }
        pats[currentPatient++] = pat;
    }
    size_t Doctor::average()const
    {
        size_t result = 0;
        for (size_t i = 0; i < registered; i++)
        {
            result += pats[i].getVisits();
        }
        return result/currentPatient;
    }
    void Doctor::printLimit(const size_t limit)const
    {
        std::cout << "Patients over the limit---------" << std::endl;
        for (size_t i = 0; i < registered; i++)
        {
            if (pats[i].getVisits() >= limit)
            {
                pats[i].print();
            }
        }
        std::cout << "---------------------------------" << std::endl;
    }
    void Doctor::print()const
    {
        std::cout << "Patients-------------------------" << std::endl;
        for (size_t i = 0; i < registered; i++)
                pats[i].print();
            
        std::cout << "---------------------------------" << std::endl;
    }
