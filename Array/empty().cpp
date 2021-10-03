#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,8> a = {1,2,3,4,5,6,7,8};
    //array<int,0> b = {};
    
    if(a.empty()==true)
        cout<<"empty ";
    else
        cout<<"not empty";
 
    return 0;   
}