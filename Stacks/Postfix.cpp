#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Function to evaluate a given postfix expression
int evalPostfix(string exp)
{
    // create an empty stack
    stack<int> stack;

    // traverse the given expression
    for (char c : exp)
    {
        // if the current character is an operand, push it into the stack
        if (c >= '0' && c <= '9')
        {
            stack.push(c - '0');
        }
        // if the current character is an operator
        else
        {
            // remove the top two elements from the stack
            int x = stack.top();
            stack.pop();

            int y = stack.top();
            stack.pop();

            // evaluate the expression 'x op y', and push the
            // result back to the stack
            if (c == '+')
            {
                stack.push(y + x);
            }
            else if (c == '-')
            {
                stack.push(y - x);
            }
            else if (c == '*')
            {
                stack.push(y * x);
            }
            else if (c == '/')
            {
                stack.push(y / x);
            }
        }
    }

    // At this point, the stack is left with only one element, i.e.,
    // expression result
    return stack.top();
}

int main()
{
    string exp = "138*+";

    cout << evalPostfix(exp);

    return 0;
}