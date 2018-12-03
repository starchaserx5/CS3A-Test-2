#include "fraction.h"

std::ostream& operator<<(std::ostream& out, const Fraction &frac)
{
    out<<frac.num;
    if(frac.denom != 1)
        out<<'/'<<frac.denom;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction &frac)
{
//    abse whole
//          whole getnum/abs whole getnum
    char junk;
    frac.num = 0;
    frac.denom = 1;
    bool neg = false;
    if(in.peek() == '-')
        neg = true;
    if(in>>frac.num)
    {
        if(in.peek() == '/')
        {
            in>>junk>>frac.denom;
        }
        else if(in.peek() == '.')
        {
            std::string s;
            int zero = frac.num;
            int decimalPart;
            std::stringstream toDouble;
            in>>junk;
            if(in.peek() == '-')
            {
                throw INVALID_INPUT;
            }
            in>>decimalPart;
            toDouble<<frac.num<<'.';
            toDouble<<decimalPart;
            toDouble>>s;
            frac = Fraction(stod(s));
            if(neg && zero == 0)
                frac.num *= -1;
        }
    }
    else
        throw INVALID_INPUT;
    frac.reduce();
    if(frac.denom == 0)
        throw DIVIDING_0;
    return in;
}

Fraction operator+(const Fraction &x,const Fraction &y)
{
    int num = x.num * y.denom + y.num * x.denom,
        denom = x.denom * y.denom;
    Fraction result(num,denom);
    return result;
}

Fraction operator-(const Fraction &x,const Fraction &y)
{
    int num = x.num * y.denom - y.num * x.denom,
        denom = x.denom * y.denom;
    Fraction result(num,denom);
    return result;
}

Fraction operator*(const Fraction &x,const Fraction &y)
{
    int num = x.num * y.num,
        denom = x.denom * y.denom;
    Fraction result(num,denom);
    return result;
}

Fraction operator/(const Fraction &x,const Fraction &y)
{
    int num = x.num * y.denom,
        denom = x.denom * y.num;
    Fraction result(num,denom);
    return result;
}

Fraction operator^(const Fraction &x,const Fraction &y)
{
    double temp1 = pow(pow(x.num, y.num),1./y.denom),
           temp2 = pow(pow(x.denom, y.num),1./y.denom);
    return temp1/temp2;
}

bool operator==(const Fraction &x,const Fraction &y)
{
    return x.num * y.denom == y.num * x.denom;
}

bool operator!=(const Fraction &x,const Fraction &y)
{
    return x.num * y.denom != y.num * x.denom;
}

bool operator>=(const Fraction &x,const Fraction &y)
{
    return x.num * y.denom >= y.num * x.denom;
}

bool operator<=(const Fraction &x,const Fraction &y)
{
    return x.num * y.denom <= y.num * x.denom;
}

bool operator>(const Fraction &x,const Fraction &y)
{
    return x.num * y.denom > y.num * x.denom;
}

bool operator<(const Fraction &x,const Fraction &y)
{
    return x.num * y.denom < y.num * x.denom;
}
