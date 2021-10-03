#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 8> a = {1,2,3,4,5};
    
    cout<<"address of begining "<<a.begin()<<endl;
    cout<<"address of end "<<a.end();
    return 0;   
}