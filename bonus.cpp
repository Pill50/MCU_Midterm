#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string suffixWithUnit(double number)
{
        string suffix[9] = {" ", " Kilo", " Mega", " Giga", " Tera", " Peta", " Exa", " Zetta", " Yotta"};
        string res = "";
        // store decimal after div 1000
        string newDecimal;
        // temporary variable to process avoid modify in "number"
        double tmp = number;
        int counter = 0;
        while (tmp >= 1000)
        {
                counter++;
                tmp = tmp / 1000;
                double decimal = tmp - int(tmp);
                tmp = (int)tmp;
                // delete "0."
                string dec = to_string(decimal).substr(2);
                // delete all 0: Ex after 3 "123000"
                dec.erase(dec.find_last_not_of('0') + 1);
                newDecimal = dec + newDecimal;
        }
        if (counter == 0)
        {
                int realpart = (int)tmp;
                double decimal = tmp - (int)tmp;
                // deleta "0."
                string deci = to_string(decimal).substr(2);
                // delete all 0: Ex after 3 "123000"
                deci.erase(deci.find_last_not_of('0') + 1);
                newDecimal = deci + newDecimal;
                res = to_string(realpart);
                if (newDecimal.length() != 0)
                        res = res + "." + newDecimal;
        }
        else
        {
                // get realpart value
                int realpart = (int)tmp;
                res = to_string(realpart);
                if (newDecimal.length() != 0)
                {
                        res = res + "." + newDecimal;
                }
                res = res + suffix[counter];
        }
        return res;
}

int main()
{
        string s = suffixWithUnit(1234.56);
        cout << s;
}