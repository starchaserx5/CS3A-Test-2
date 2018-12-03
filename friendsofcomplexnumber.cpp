#include "complexnumber.h"


std::ostream& operator<<(std::ostream& out, const complexNumber& c)
{
    if(&out == &std::cout)
    {
        if(c.real != 0)
        {
            out<<c.real;
            if(c.imaginary != 0)
            {
                if(c.imaginary > 0)
                    out<< " + ";
                if(c.imaginary < 0)
                    out<< " - ";

                if(c.imaginary == 1 || c.imaginary == -1)
                    out<<"i";
                else
                {
                    if(c.imaginary < 0)
                    {
                        mixedNumber temp;
                        temp = c.imaginary;
                        temp = c.imaginary * -1;
                        out<<temp<<"i";
                    }
                    else
                    {
                        out<<c.imaginary<<"i";
                    }
                }
            }
        }
        else if(c.imaginary != 0)
        {
            if(c.imaginary == 1)
                out<<"i";
            else if(c.imaginary == -1)
                out<<"-i";
            else
                out<<c.imaginary<<"i";
        }
        else
            out<<0;
    }
    else
        out<<c.real<<' '<<c.imaginary;
    return out;
}


std::istream& operator>>(std::istream& in, complexNumber& c)
{
    char junk,op1 = '+',op2;
    c.real = c.imaginary =0;
    if(in.peek() == '-')
        in>>op1;
    if(in.peek() == 'I')
    {
        in>>junk;
        c.real = 0;
        c.imaginary = 1;
        if(op1 == '-')
            c.imaginary *= mixedNumber(-1);
    }
    else if(in>>c.real)
    {
        if(op1 == '-')
            c.real *= mixedNumber(-1);
        if(in.peek() == 'I')
        {
            in>>junk;
            c.imaginary = c.real;
            c.real = 0;
        }
        else if(in.peek() == '+' || in.peek() == '-')
        {
            in>>op2;
            if(in.peek() == 'I')
            {
                in>>junk;
                c.imaginary = 1;
                if(op2 == '-')
                    c.imaginary *= -1;
            }
            else
            {
                in>>c.imaginary;
                if(op2 == '-')
                    c.imaginary *= mixedNumber(-1);
                if(in.peek() == 'I')
                    in>>junk;
                else
                std::cout<<"missing i";
            }
        }
    }
    else
    {
        std::string s;
        in>>s;
        std::cout<<s<<std::endl;
        std::cout<<"error on impit";
    }
    return in;
}


complexNumber operator+(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    temp.real = x.real + y.real;
    temp.imaginary = x.imaginary + y.imaginary;
    return temp;
}


complexNumber operator-(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    temp.real = x.real - y.real;
    temp.imaginary = x.imaginary - y.imaginary;
    return temp;
}


complexNumber operator*(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    temp.real = (x.real*y.real) - (x.imaginary*y.imaginary);
    temp.imaginary = (x.real*y.imaginary) + (x.imaginary*y.real);
    return temp;
}

complexNumber operator/(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    temp.real = ((x.real * y.real) + (x.imaginary * y.imaginary))/((y.real^2) + (y.imaginary^2));
    temp.imaginary = ((x.imaginary * y.real) - (x.real * y.imaginary))/((y.real^2) + (y.imaginary^2));
    return temp;
}

complexNumber operator^(const complexNumber &x, const complexNumber &y)
{
    double PI = M_PI;
    mixedNumber z,r, angle, rads;
    r = ((x.real^2)+(x.imaginary^2))^(.5);
    if(x.imaginary == 0 && x.real == 0)
        angle = 0;
    else
        angle = atan(z.toDouble(x.imaginary/x.real)) * 180 / PI;
    if(x.real < 0)
        angle = 180+angle;
    else if(x.real >= 0 && x.imaginary < 0)
        angle = 360+angle;

    rads = angle*(PI/180);

    std::cout << r << " , " << rads << " rads" << std::endl;

    /*double a = m.toDouble(x.real),
               b = m.toDouble(x.imaginary),
               c = m.toDouble(y.real),
               d = m.toDouble(y.imaginary),*/

    double rNumber = pow(r.toDouble(r),angle.toDouble(y.real)) * exp(rads.toDouble(rads*-1) * angle.toDouble(y.imaginary));
    double temp2 = angle.toDouble(y.imaginary) * r.toDouble(log(r.toDouble(r))) + (rads.toDouble(rads) * angle.toDouble((y.imaginary)));

    std::cout << "This is rNumber: " << rNumber << std::endl;
    std::cout << "This is temp2: " << temp2 << std::endl;

    //turn into complex number now
    complexNumber a(rNumber * cos(temp2), rNumber * sin(temp2));

    std::cout << "The answer is: " << a.real << " and " << a.imaginary << std::endl;
    return a;
}

bool operator==(const complexNumber &x, const complexNumber &y)
{
    if(x.real == y.real && x.imaginary == y.imaginary)
        return true;
    return false;
}

void Trig(const complexNumber &other)
{
    double PI = M_PI;
    mixedNumber z,r, angle;
    r = ((other.real^2)+(other.imaginary^2))^(.5);
    if(other.imaginary == 0 && other.real == 0)
        angle = 0;
    else
        angle = atan(z.toDouble(other.imaginary/other.real)) * 180 / PI;
    if(other.real < 0)
        angle = 180+angle;
    else if(other.real >= 0 && other.imaginary < 0)
        angle = 360+angle;

   // std::cout<<r<<"(cos("<<angle<<")"<<"+ isin("<<angle<<"))";
    std::cout<<r<<" , "<<angle * (PI/180)<<" rads";
}

complexNumber Conjugate(const complexNumber &other)
{
    complexNumber temp;
    temp.real = other.real;
    temp.imaginary = other.imaginary * -1;
    return temp;
}

mixedNumber Magnitude(const complexNumber &other)
{
    mixedNumber r;
    r = ((other.real^2)+(other.imaginary^2))^(.5);
    return  r;
}


/*int first = c.find('(');
    int last = c.find(')');
    std::string frac = c.substr(first+1,last-2);*/


complexNumber Polar(mixedNumber &magnitude, mixedNumber &angle)
{
    //turn into complex number now
    complexNumber d;
    mixedNumber temp1, temp2;
    std::cout << "Enter your magnitude: " << std::endl;
    std::cin >> temp1;

    std::cout << "Enter your angle: " << std::endl;
    std::cin >> temp2;

    std::cout << "This is the magnitude: " << temp1 << std::endl;
    std::cout << "This is the angle: " << temp2 << std::endl;

    complexNumber a(d.toDouble(temp1) * cos(d.toDouble(temp2)), d.toDouble(temp1) * sin(d.toDouble(temp2)));;
    return a;
}



