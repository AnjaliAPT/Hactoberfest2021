#include <iostream>
using namespace std;

// 0 1 1 2 3 5 8 13 ..... --> fibonacci series;

// 0--> 0th fib;  --> base case;
// 1--> 1st fib;  --> base case;
// 1--> 2nd fib;
// 2--> 3rd fib;

int fib(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // we require 2 base cases coz we are accessing
    // n-1 and n-2 , both;

    // recursive case
    int smallop1 = fib(n - 1);
    int smallop2 = fib(n - 2);

    return smallop1 + smallop2;
}

int main()
{
    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}