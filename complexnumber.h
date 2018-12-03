#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
#include "mixednumber.h"
#include <cmath>
#include <string>

class complexNumber
{
public:
    complexNumber(const mixedNumber &r = 0, const mixedNumber &i = 0);
    ~complexNumber();
    complexNumber(const complexNumber &other);

    complexNumber& operator=(const complexNumber& other);
    complexNumber& operator+=(const complexNumber& other);
    complexNumber& operator-=(const complexNumber& other);
    complexNumber& operator*=(const complexNumber& other);
    complexNumber& operator/=(const complexNumber& other);

    void setComplexNumber(const mixedNumber &r = 0, const mixedNumber &i = 0);
    mixedNumber getReal();
    mixedNumber getImaginary();
    void copy(const complexNumber &other);
    double toDouble(const mixedNumber &other);

    //const mixedNumber& magnitude, const mixedNumber &angle
// evaluating and () overload?

    friend
    std::ostream& operator<<(std::ostream& out, const complexNumber& c);

    friend
    std::istream& operator>>(std::istream& in, complexNumber& c);

    friend
    complexNumber operator+(const complexNumber &x, const complexNumber &y);

    friend
    complexNumber operator-(const complexNumber &x, const complexNumber &y);

    friend
    complexNumber operator*(const complexNumber &x, const complexNumber &y);

    friend
    complexNumber operator/(const complexNumber &x, const complexNumber &y);

    friend
    bool operator==(const complexNumber &x, const complexNumber &y);

    friend
    complexNumber operator^(const complexNumber &x, const complexNumber &y);

    friend
    complexNumber Polar(mixedNumber &magnitude, mixedNumber &angle);

    friend
    void Trig(const complexNumber &other);

    friend
    complexNumber Conjugate(const complexNumber &other);

    friend
    mixedNumber Magnitude(const complexNumber &other);

private:
    mixedNumber real, imaginary;
};

#endif // COMPLEXNUMBER_H
