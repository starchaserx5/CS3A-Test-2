#ifndef MIXEDNUMBER_H
#define MIXEDNUMBER_H

#include <iostream>
#include <fstream>
#include "fraction.h"

class mixedNumber : public Fraction
{
    public:
        mixedNumber();
        ~mixedNumber();
        mixedNumber(const double &other);
        mixedNumber(int w, int n, int d);
        mixedNumber(const mixedNumber &other);
        mixedNumber& operator=(const mixedNumber &other);
        mixedNumber& operator=(const Fraction &other);
        mixedNumber& operator=(const int &other);
        mixedNumber& operator=(const double &other);

        void getValues(int &w, int &n, int &d);
        void setValues(int w, int n, int d);

        friend
        std::ostream& operator<<( std::ostream &out, const mixedNumber &m);

        friend
         std::istream& operator>>( std::istream &in, mixedNumber &m);

    private:

        void copy(const mixedNumber &other);
        void nukeEveryone();
};

#endif // MIXEDNUMBER_H
