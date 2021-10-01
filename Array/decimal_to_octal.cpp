#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int octal[32];
	int i=0;
	while(n>0)
	{
		octal[i]=n%8;
		n/=8;
		i++;
	}
for(int j=i-1;j>=0;j--)
{
	cout<<octal[j];
}

return 0;
}