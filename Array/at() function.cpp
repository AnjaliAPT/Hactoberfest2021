#include <iostream>

#include <array>

using namespace std;


int main()
{
    array<int,9> num= {1,2,3,4,5,6,7,8,9};
    
    cout << num.at(2)<<endl;    // prints 3
    cout << num.at(6);     // prints 7
}