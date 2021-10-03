#include <iostream>

#include <array>

using namespace std;


int main()
{
    array<int,9> num;
    
    //num.fill(1);
    
    num.fill(5);
    
    cout<<num[5];
}