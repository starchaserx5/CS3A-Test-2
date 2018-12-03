#include "complexnumber.h"

complexNumber::complexNumber(const mixedNumber &r, const mixedNumber &i)
{
    setComplexNumber(r,i);
}

complexNumber::~complexNumber()
{
    real = imaginary = 0;
}

complexNumber::complexNumber(const complexNumber &other)
{
    copy(other);
}

complexNumber& complexNumber::operator=(const complexNumber& other)
{
    if(this != &other)
        copy(other);
    return *this;
}

complexNumber& complexNumber::operator+=(const complexNumber& other)
{
    *this = *this + other;
    return *this;
}

complexNumber& complexNumber::operator-=(const complexNumber& other)
{
    *this = *this - other;
    return *this;
}

complexNumber& complexNumber::operator*=(const complexNumber& other)
{
    *this = *this * other;
    return *this;
}

complexNumber& complexNumber::operator/=(const complexNumber& other)
{
    *this = *this / other;
    return *this;
}

void complexNumber::setComplexNumber(const mixedNumber &r, const mixedNumber &i)
{
    real = r;
    imaginary = i;
}

mixedNumber complexNumber::getReal()
{
    return real;
}

mixedNumber complexNumber::getImaginary()
{
    return imaginary;
}

void complexNumber::copy(const complexNumber &other)
{
    real = other.real;
    imaginary = other.imaginary;
}

double complexNumber::toDouble(const mixedNumber &other)
{
    double d;
    d = (other.getNum()/(double)other.getDenom());
    return d;
}
