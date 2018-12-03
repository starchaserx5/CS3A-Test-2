#ifndef MEMORIES_H
#define MEMORIES_H

#include "complexnumber.h"
#include <vector>

class memories
{
public:
    memories();
    ~memories();

    complexNumber operator[](int i) const;
    complexNumber& operator[](int i);

private:
    std::vector<complexNumber> cNumber;
};

#endif // MEMORIES_H
