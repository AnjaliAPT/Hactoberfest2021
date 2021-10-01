#include<iostream>
using  namespace std;
long long  int fact(int  n)
{
	long long int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans = ans * i;
	}
	return ans;
}

long long int nCr(int n, int r)
{
	long long int ans = fact(n) / (fact(n - r) * fact(r));
	return ans;
}


 
int main()
{
	int n, r;
	cin >> n >> r;
	cout << fact(n) << endl;
	cout << nCr(n, r);

}