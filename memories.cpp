#include "memories.h"

memories::memories()
{
    cNumber.resize(26);
}

memories::~memories()
{
    cNumber.clear();
}

complexNumber memories::operator[](int i) const
{
    return cNumber[i];
}

complexNumber& memories::operator[](int i)
{
    return cNumber[i];
}
