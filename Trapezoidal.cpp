#include<iostream>
#include<math.h>
using namespace std;
float f(float x)
  {
     return sqrt(1+x*x); 
   }
  int main()
  { float a[20],b[20],x[20],ans=0;
    float u,l;
    int n;
    float h,t;
  cout<<"enter the no of strips you want"<<endl;
  cin>>n;
  cout<<"enter the limits upper and lower"<<endl;
  cin>>u>>l;
cout<<"upperlimit="<<u<<"  "<<"lowerlimit="<<l; 

h=(u-l)/n;

cout<<endl<<h<<endl;
for(int i=0;i<=n;i++)
{
 a[i]=l+i*h;
 b[i]=f(a[i]);
 cout<<b[i]<<" ";
}
for(int i=1;i<n;i++)
{
ans=ans+b[i]; 
}
ans=(h/2)*(b[0]+b[n])+h*ans;

cout<<endl<<"answer"<<ans<<endl;
return 0;
}


