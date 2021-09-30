#include<iostream>
using namespace std;
int main()
{
    int n1,n2,num[100],max,min;
    cout<<"How many numbers: ";
    cin>>n2;
    cout<<"\n\n";
    for(n1=0;n1<n2;n1++)
    {
        cout<<"Enter "<<(n1+1)<<"th number: ";
        cin>>num[n1];
    }
     max=num[0];
     for(n1=1;n1<n2;n1++)
     {
        if(num[n1]>max)
        {
            max=num[n1];
        }
     }
      min=num[0];
      for(n1=1;n1<n2;n1++)
     {
        if(num[n1]<min)
        {
            min=num[n1];
        }
     }
     cout<<"\nBiggest number is "<<max<<" & Smallest number is "<<min<<"\n";
     return 0;
}
