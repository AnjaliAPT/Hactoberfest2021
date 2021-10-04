#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        int t;
        cin>>t;
        while(t--)
        {
            int a,b;
            cin >> a >> b;
            cout << ((a+b)%3==0 && (abs(a-b)<=min(a,b)) ? "YES" : "NO") << '\n';
        }
        return(0);
}
