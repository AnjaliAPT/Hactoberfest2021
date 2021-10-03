#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,8> a = {1,2,3,4,5,6,7,8};
    array<int,8> b = {8,7,6,5,4,3,2,1};
    
    a.swap(b); // swaps array a and b
    
    cout << "a is : ";
    
    for(int i=0; i < 8; i++)
    {
    cout << a[i] <<" ";
    }
    cout << endl;
    cout << "b is : ";
    for(int i=0; i < 8; i++)
    {
    cout << b[i] <<" ";
    }
    
}