#ifndef Fraction_H
#define Fraction_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

enum fraction_ERRORS {DIVIDING_0, INVALID_INPUT};

class Fraction
{
public:
    Fraction(int n = 0, int d = 1);
    Fraction(const double &other);
    ~Fraction();
    Fraction(const Fraction &other);

    Fraction& operator=(const Fraction &other);
    Fraction& operator+=(const Fraction &other);
    Fraction& operator-=(const Fraction &other);
    Fraction& operator*=(const Fraction &other);
    Fraction& operator/=(const Fraction &other);

    int getNum() const;
    int getDenom() const;
    void setValue(int n = 0, int d = 1);
    void doubletofrac(const double &other);
    double toDouble(const Fraction &other);

    friend
    std::ostream& operator<<(std::ostream& out, const Fraction &frac);

    friend
    std::istream& operator>>(std::istream& in, Fraction &frac);

    friend
    Fraction operator+(const Fraction &x, const Fraction &y);

    friend
    Fraction operator-(const Fraction &x, const Fraction &y);

    friend
    Fraction operator*(const Fraction &x, const Fraction &y);

    friend
    Fraction operator/(const Fraction &x, const Fraction &y);

    friend
    Fraction operator^(const Fraction &x, const Fraction &y);

    friend
    bool operator==(const Fraction &x,const Fraction &y);

    friend
    bool operator!=(const Fraction &x,const Fraction &y);

    friend
    bool operator>=(const Fraction &x,const Fraction &y);

    friend
    bool operator<=(const Fraction &x,const Fraction &y);

    friend
    bool operator>(const Fraction &x,const Fraction &y);

    friend
    bool operator<(const Fraction &x,const Fraction &y);

protected:
    int num, denom;

private:
    void reduce();
    int gcd(int p, int q);

    bool allDecimalsTheSame(std::string &fracPart);
    int makeDenom(int digits, bool same);
};

#endif // Fraction_H
