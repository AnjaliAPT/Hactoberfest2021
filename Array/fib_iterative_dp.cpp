#include <iostream>
using namespace std;
unsigned long long int  fib_(unsigned long long n)
{
   unsigned long long *a=new unsigned long long[n+1];
	a[0]=a[1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	unsigned long long ans =a[n];
	delete []a;
	return ans; 

}

unsigned long long int fib_op(unsigned long long int n)
{
	if(n==0 or n==1)
	{
		return n;
	}
	unsigned long long int a=0,b=1,c;
	for(unsigned long long  i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}


int main()
{
	unsigned long long int n;
	cin>>n;
	for(unsigned long long int i=0;i<=n;i++)
	{
		cout<<fib_op(i)<<endl;
	}
}

