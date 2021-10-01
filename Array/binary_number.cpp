#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	int p=1;
	while(n>0)
	{
		int last_digit=n%10;
		ans+=last_digit*p;
		p*=2;
		n=n/10;

	}cout<<ans;


}