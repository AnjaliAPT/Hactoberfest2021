#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    int k = 1;
    ll sum = 0;
    while (n >= pow(5, k))
    {
        sum += n / pow(5, k);
        k++;
    }
    cout << sum << endl;
}
