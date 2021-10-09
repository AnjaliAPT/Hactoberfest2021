#include <iostream>
#include <stack>
using namespace std;

// Stack implementation in C++ using `std::stack`
int main()
{
    stack<string> s;

    s.push("A"); // Insert `A` into the stack
    s.push("B"); // Insert `B` into the stack
    s.push("C"); // Insert `C` into the stack
    s.push("D"); // Insert `D` into the stack

    // returns the total number of elements present in the stack
    cout << "The stack size is " << s.size() << endl;

    // prints the top of the stack (`D`)
    cout << "The top element is " << s.top() << endl;

    s.pop(); // removing the top element (`D`)
    s.pop(); // removing the next top (`C`)

    cout << "The stack size is " << s.size() << endl;

    // check if the stack is empty
    if (s.empty())
    {
        cout << "The stack is empty\n";
    }
    else
    {
        cout << "The stack is not empty\n";
    }

    return 0;
}