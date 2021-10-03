#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 8> a = {1,2,3,4,5};
    
    cout<<"element in array"<<a.size()<<endl;
    cout<<"total size of array"<<a.max_size();
 
    return 0;   
}