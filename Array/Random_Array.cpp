#include <iostream>
using namespace std;

int main()
{
   int sz;
   cout<<"Enter the size of array::";
   cin>>sz;
   int randArray[sz];
   for(int i=0;i<sz;i++)
      randArray[i]=rand()%100;  //Generate number between 0 to 99
  
   cout<<"\nElements of the array::"<<endl;
  
   for(int i=0;i<sz;i++)
      cout<<"Elements no "<<i+1<<"::"<<randArray[i]<<endl;
   return 0;
}
