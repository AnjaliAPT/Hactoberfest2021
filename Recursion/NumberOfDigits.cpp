#include <iostream>
using namespace std;

int count(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    // recursive case
    return 1 + count(n / 10);
}

int main()
{
    int n;
    cin >> n;

    cout << count(n) << endl;

    return 0;
}