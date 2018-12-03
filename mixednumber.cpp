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

mixedNumber& mixedNumber::operator=(const Fraction &other)
{
    num = other.getNum();
    denom = other.getDenom();
    return *this;
}


mixedNumber& mixedNumber::operator=(const int &other)
{
    Fraction temp(other);
    *this = temp;
    return *this;
}

mixedNumber& mixedNumber::operator=(const double &other)
{
    Fraction temp(other);
    *this = temp;
    return *this;
}

void mixedNumber::getValues(int &w, int &n, int &d)
{
    w = num/denom;
    n = num%denom;
    d = denom;
}

void mixedNumber::setValues(int w, int n, int d)
{
    Fraction::setValue(w*d + n, d);
}

void mixedNumber::copy(const mixedNumber &other)
{
    num = other.num;
    denom = other.denom;
}

void mixedNumber::nukeEveryone()
{
    num = 0;
    denom = 1;
}

 std::ostream& operator<<( std::ostream &out, const mixedNumber &m)
{
     int whole = m.num/m.denom, numerator = m.num % m.denom;
     if(numerator == 0)
         out<<whole;
     else
         if(whole == 0)
             out<<numerator<<"/"<<m.denom;
        else
             out<<whole<<" "<<abs(numerator)<<"/"<<m.denom;
     return out;
}

std::istream& operator>>( std::istream &in, mixedNumber &m)
{
     Fraction whole(0), part(0);

     in>>whole;
     if(in.peek() == ' ')
     {
         in>>part;
         Fraction total(abs(whole.getNum())*part.getDenom()+part.getNum(),part.getDenom());
         std::cout << "The total1 here is: " << total << std::endl;
         total = total * abs(whole.getNum())/whole.getNum();
                  std::cout << "The total2 here is: " << total << std::endl;
         m.setValues(0,total.getNum(),total.getDenom());
                  std::cout << "The total3 here is: " << total << std::endl;
     }
     else
     m.setValues(0,whole.getNum(),whole.getDenom());


     return in;
}
