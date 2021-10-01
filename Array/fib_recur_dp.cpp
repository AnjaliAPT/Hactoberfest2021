#include <iostream>
using namespace std;
unsigned long long fib(int n,unsigned long long  *a)
{ long long ans=0;
	if(n==0)
	{
	    a[n]=ans;
		return 0;
	}
	if(n==1)
	{
	    a[n]=ans;
		return 1;
	}

	if(a[n]>0)
	{
		return a[n];
	}
	 ans=fib(n-1,a)+fib(n-2,a);
	a[n]=ans;
	return ans;
}
unsigned long long  a[100000000]={0};
int main()
{ 
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<fib(i,a)<<endl;
	}
	
}