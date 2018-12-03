#include "mixednumber.h"

mixedNumber::mixedNumber()
{
}

mixedNumber::~mixedNumber()
{
    nukeEveryone();
}

mixedNumber::mixedNumber(int w, int n, int d)
{
    setValues(w,n,d);
}


mixedNumber::mixedNumber(const double &other)
{
    doubletofrac(other);
}

mixedNumber::mixedNumber(const mixedNumber &other)
{
    copy(other);
}

mixedNumber& mixedNumber::operator=(const mixedNumber &other)
{
    if(this != &other)
       copy(other);
    return *this;
}
