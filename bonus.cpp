#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string suffixWithUnit(double number)
{
        string suffix[9] = {" ", " Kilo", " Mega", " Giga", " Tera", " Peta", " Exa", " Zetta", " Yotta"};
        string res = "";
        // store decimal after div 1000
        string newDec;
        // temporary variable to process
        double tmp = number;
        int counter = 0;
        while (tmp >= 1000)
        {
                tmp = tmp / 1000;
                counter++;
                // get decimal value
                double decimal = tmp - int(tmp);
                // erase "0."
                string dec = to_string(decimal).substr(2);
                // erase all trailing zeros
                dec.erase(dec.find_last_not_of('0') + 1);
                newDec = dec + newDec;
                tmp = (int)tmp;
        }
        if (counter == 0)
        {
                // get realpart
                int realpart = (int)tmp;
                // get decimal
                double decimal = tmp - (int)tmp;
                // erase "0."
                string dec = to_string(decimal).substr(2);
                // erase all trailing zeros
                dec.erase(dec.find_last_not_of('0') + 1);
                newDec = dec + newDec;
                res = to_string(realpart);
                if (newDec.length() != 0)
                        res = res + "." + newDec;
        }
        else
        {
                // get realpart value
                int realpart = (int)tmp;
                res = to_string(realpart);
                if (newDec.length() != 0)
                { // add "."
                        res = res + "." + newDec;
                }
                res = res + suffix[counter];
        }
        return res;
}

int main()
{
        string s = suffixWithUnit(123.456);
        cout << s;
}