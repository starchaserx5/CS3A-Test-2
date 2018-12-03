#include <iostream>
#include "fraction.h"
#include "mixednumber.h"
#include "complexnumber.h"
#include "memories.h"
#include <string>
#include <map>

using namespace std;

enum calculate_ERRORS {COMMAND_LINE_INVALID, INVALID_COMMAND, FILE_NOT_EXIST, FILENAME_EMPTY};

typedef void(*userInput)(memories &m, const string c);

bool getInput(std::string &s, std::string &c, std::istream &in, std::vector<std::string> &v, bool b, const std::string &filename);

void loadfunctions(userInput list[], std::map<std::string,int> &m);

void error(memories &m, const string c);
void let(memories &m, const std::string c);
void doMath(memories &m, const std::string c);
void toTrig(memories &m, const std::string c);
void print(memories &m, const std::string c);
void writeToFile(memories &m, const std::string c);
void readFromFile(memories &m, const std::string c);
void exit(memories &m, const std::string c);
void magnitude(memories &m, const std::string c);

void stringCutter(std::string &s, std::string &c, std::string &sv);
void removeSpaces(std::string &s);
void capitalize(std::string &s);
void menu();
void doMathHelp(std::string &s, std::string &c);
void fixMixedNums(string &s);

int main()
{
    menu();

    return 0;
}

void menu()
{
    memories cNum;
    vector<complexNumber> cs;
    std::vector<std::string> execute;
    userInput whatToDo[10];
    std::map<std::string,int> cntrl;
    loadfunctions(whatToDo, cntrl);
    std::string *list, filename, command, rest;;
    bool copyInput = false;

    while(getInput(command,rest,std::cin,execute,copyInput,filename))
    {
        try
        {
            doMathHelp(command, rest);
            cout<<command<<endl;
            (whatToDo[cntrl[command]])(cNum, rest);
            command=rest="";
        }
        catch (fraction_ERRORS e)
        {
            switch(e)
            {
            case INVALID_INPUT: std::cout<<"ERROR: Invalid Input\n"
                                      "Please put valid integers before an x or decimal ex. 1x, 0.5\n"
                                      "Also check if the power (^), equal(=) is there and only variable x!\n"
                                      "lastly put spaces before the (=) and commands and only expressions can add\n"
                                           "to each other"<<std::endl;
                break;
            case DIVIDING_0: std::cout<<"ERROR: Denominator cannot be zero!"<<std::endl;
                break;
            }
        }
//        catch (term_ERRORS e)
//        {
//            switch(e)
//            {
//            case MISSING_POWER_SIGN: std::cout<<"ERROR: If powers are being used dont forget (^) sign"<<std::endl;
//                break;
//            case COEFF_0 : std::cout<<"ERROR: COEFF CANT BE 0 if there is a variable\n";
//            }
//        }
        catch (calculate_ERRORS e)
        {
            switch(e)
            {
            case FILENAME_EMPTY: std::cout<<"ERROR: Filename is empty."<<std::endl;
                break;
            case FILE_NOT_EXIST: std::cout<<"ERROR: Filename Does not exist"<<std::endl;
                break;
            case INVALID_COMMAND: std::cout<<"ERROR: Command invalid, please type /h or /? as one parameter\n"
                                        "in command line for help."<<std::endl;
            }
        }
        catch(...) // "Catch all" gets anything that you "forgot" to cover
        {
            std::cout<<"An unknown error occurred."<<std::endl;
        }
    }
    std::cout<<"No Input, Exiting";
}

void loadfunctions(userInput list[], std::map<std::string, int> &m)
{
    m["DOMATH"] = 1;
    m["LET"]= 2;
    m["TRIG"]= 3;
    m["PRINT"]= 4;
  //  m["SAVE"] = 5;
  //  m["LOAD"] = 6;
   // m["EXIT"] = 7;
    m["MAGNITUDE"] = 8;
    list[0] = error;
    list[1] = doMath;
    list[2] = let;
    list[3] = toTrig;
    list[4] = print;
//    list[5] = writeToFile;
//    list[6] = readFromFile;
//    list[7] = exit;
    list[8] = magnitude;
}

bool getInput(std::string &s, std::string &c, std::istream &in, std::vector<std::string> &v, bool b, const std::string &filename)
{
    std::string what;
    std::stringstream ss("");
    unsigned int pos = 0;
    std::cout<<"COMMAND: ";
    if(v.size()>0)
    {
        stringCutter(s, c, v[0]);
        std::cout<<"ECHO:"<<s+c<<std::endl;
        v.erase(v.begin());
    }
    else
    {
        getline(in,what);
        stringCutter(s, c, what);
    }
    //    if(b == true)
    //    {
    //        record(filename,what);
    //    }
    capitalize(s);
    removeSpaces(s);
    removeSpaces(c);
    if (s != "SAVE" && s != "LOAD")
    {
        capitalize(c);
    }
    return !s.empty();
}

void stringCutter(std::string &s, std::string &c, std::string &sv)
{
    if(sv.find(' ') != std::string::npos)
    {
        unsigned int pos;
        pos = sv.find(' ');
        s = sv.substr(0,pos);
        c = sv.substr(pos);
    }
    else
        s = sv;
}

void removeSpaces(std::string &s)
{
    //unsigned int i;
    //    while((i = s.find(' ')) < s.size())
    //        s.erase(i,1);
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ' && !(isdigit(s[i-1]) && isdigit(s[i+1])))
        {
            s.erase(i,1);
            --i;
        }
    }
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        if(s[0] == '.')
        {
            s.insert(i, "0");
        }
        if (i>0)
        {
            if(!isdigit(s[i-1]) && s[i-1] != '.' && !isalpha(s[i-1]))
            {
                s.insert(i, "0");
            }
        }
    }
}

void capitalize(std::string &s)
{
    for(unsigned int i = 0; i < s.length(); ++i)
    {
        s[i] = toupper(s[i]);
    }
}

void doMathHelp(std::string &s, std::string&c)
{
    if(s.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") > s.size() && s.size() == 1)
    {
        c = s + c;
        s = "DOMATH";
    }
    if(s.find("TRIG") < s.size() == 1)
    {
        c = s;
        s = "TRIG";
    }
    if(s.find("MAGNITUDE") < s.size() == 1)
    {
        c = s;
        s = "MAGNITUDE";
    }
}

void error(memories &m, const string c)
{
    cout<< "INVALID_COMMAND";
}

void let(memories &m, const std::string c)
{
    std::stringstream ss("");
    char letter = c[0];
    if(isalpha(c[0]))
    {
        std::string s = c.substr(c.find("=") + 1);
        //fixMixedNums(s);
        //65 is ascii of "A" - 65 for index 0;
        cout<<"this is s:"<<s<<endl<<endl;
        int i = letter-65;
        ss.str(s+'\n');
        ss>>m[i];
        std::cout<<letter<<" = "<<m[i]<<std::endl;
    }
    else
    {
        throw INVALID_INPUT;
    }
}

void print(memories &m, const std::string c)
{
    char letter = '0';
    if(isalpha(c[0]))
        letter = c[0];
    else
        throw INVALID_COMMAND;
    int i = letter-65;
    std::cout<<letter<<" = "<<m[i]<<std::endl;
}

void doMath(memories &m, const std::string c)
{
    char a,x,y;
    a = c[0]; x = c[2]; y = c[4];
    if(isalpha(c[0]) && isalpha(c[2])&& c[3] != '\''&& isalpha(c[4]))
    {
        char op = c[3];
        int ans = a-65, xx = x-65, yy = y-65;
        switch(op)
        {
        case '+' : m[ans] = m[xx] + m[yy];
            break;
        case '-' : m[ans] = m[xx] - m[yy];
            break;
        case '*' : m[ans] = m[xx] * m[yy];
            break;
        case '/' : m[ans] = m[xx] / m[yy];
            break;
//        case '^' : m[ans] = m[xx] ^ m[yy];
//            break;
        default : throw INVALID_INPUT;
        }
        std::cout<<a<<" = "<<m[ans]<<std::endl;
    }
   // F=G'
    else if(isalpha(c[0]) && isalpha(c[3]) && c[2] == '~')
    {
        for(int i = 0; i < c.size();++i)
            cout<<c[i]<<endl;
        int ans = a-65, xx = c[3]-65;
        cout<<ans<<endl;
        cout<<xx<<endl;
            m[ans] = Conjugate(m[xx]);
        std::cout<<a<<" = "<<m[ans]<<std::endl;
    }
    else
        throw INVALID_INPUT;
}

void toTrig(memories &m, const std::string c)
{
    std::stringstream ss("");
    char letter = '0';
    if(isalpha(c[5]))
        letter = c[5];
    else
        throw INVALID_COMMAND;
    int i = letter-65;
    complexNumber f;
    //Used https://stackoverflow.com/questions/18800796/c-get-string-between-two-delimiter-string
//    int first = c.find('(');
//    int last = c.find(')');
//    std::string frac = c.substr(first+1,last-2);
//    ss.str(frac);
//    ss>>f;
    Trig(m[i]);
    std::cout<<std::endl;
//    std::cout<<letter<<"("<<f<<")"<<" = "<<Trig(f)<<std::endl;
}

void magnitude(memories &m, const std::string c)
{
    if(!isalpha(c[10]))
        throw INVALID_COMMAND;
    int x = c[10] - 65;
    Magnitude(m[x]);
    std::cout<<"Magnitude: "<< Magnitude(m[x]);
}
