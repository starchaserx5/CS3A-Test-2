#include "fraction.h"

Fraction::Fraction(int n, int d)
{
    setValue(n,d);
}

Fraction::Fraction(const double &other)
{
    doubletofrac(other);
}

Fraction::~Fraction()
{
    num = denom = 0;
}

Fraction::Fraction(const Fraction &other)
{
    num = other.num;
    denom = other.denom;
}

Fraction& Fraction::operator=(const Fraction &other)
{
    if(this != &other)
    {
        num = other.num;
        denom = other.denom;
    }
    return *this;
}

Fraction& Fraction::operator+=(const Fraction &other)
{
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction &other)
{
    *this = *this - other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction &other)
{
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction &other)
{
    *this = *this / other;
    return *this;
}

int Fraction::getNum() const
{
    return num;
}

int Fraction::getDenom() const
{
    return denom;
}

void Fraction::setValue(int n, int d)
{
    num = n;
    denom = d;
    reduce();
}

void Fraction::reduce()
{
    bool neg = num < 0 || denom < 0,
         both = num < 0 && denom < 0;
    int divisor = gcd(abs(num), abs(denom));
    num = abs(num) / divisor;
    denom = abs(denom) / divisor;
    if(!both)
        if(neg)
            num *= -1;
}

int Fraction::gcd(int p, int q)
{
    return !q ? p : gcd(q, p%q);
}

bool Fraction::allDecimalsTheSame(std::string &fracPart)
{
    bool yes = false;
    if (fracPart.size() >= 5)
    {
        yes = true;
        for(int i = 1; yes && i < fracPart.size(); ++i)
            yes = (fracPart[0] == fracPart[i]);
    }
    if(!yes && fracPart.size() == 5)
    {
        yes = true;
        for(int i = 0; yes && i < fracPart.size() - 1; ++i)
            yes = (fracPart[i] == fracPart[4]-1);
        if(yes)
            fracPart[4] = fracPart[4] - 1;
    }
    return yes;
}

int Fraction::makeDenom(int digits, bool same)
{
    std::string result("1");
    for(int i = 0; i < digits; ++i)
        result += "0";
    return std::stoi(result) - static_cast<int>(same);
}

void Fraction::doubletofrac(const double &other)
{
    std::string wholePart, FractionPart;
    std::stringstream ss;
    ss<<other;
    getline(ss,wholePart,'.');
    getline(ss,FractionPart);
    if(FractionPart.empty())
        FractionPart = '0';
    int numDigits = FractionPart.size();
    denom = makeDenom(numDigits, allDecimalsTheSame(FractionPart));
    if(stoi(wholePart) < 0)
        num = denom * std::stoi(wholePart) - std::stoi(FractionPart);
    else
        num = denom * std::stoi(wholePart) + std::stoi(FractionPart);
    reduce();
}

double Fraction::toDouble(const Fraction &other)
{
    double d;
    d = (other.getNum()/(double)other.getDenom());
    return d;
}
