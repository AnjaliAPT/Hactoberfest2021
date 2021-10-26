C++ Program to Convert Octal Number to Binary
/*  C++ Program to Convert Octal Number to Binary  */

#include <iostream>
#include <cmath>

using namespace std;

long long convertOctalToBinary(int);
int main()
{
    int octalNumber;

    cout << "Enter an octal number: ";
    cin >> octalNumber;

     cout <<"\n [ "<< octalNumber << " ] in octal = [ " << convertOctalToBinary(octalNumber) << " ] in binary\n";

    return 0;
}

long long convertOctalToBinary(int octalNumber)
{
    int decimalNumber = 0, i = 0;
    long long binaryNumber = 0;

    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }

    return binaryNumber;
}
OUTPUT : :
/*  C++ Program to Convert Octal to Binary  */

Enter an octal number: 454

 [ 454 ] in octal = [ 100101100 ] in binary

Process returned 0
Above is the source code for C++ Program to Convert Octal to Binary which is successfully compiled and run on Windows System.The Output of the program is shown above .
