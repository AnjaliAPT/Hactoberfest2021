#include <iostream>
#include <string.h>
#include <iterator>
#include <map>
#include <math.h>
#include <bits/stdc++.h>
//#include<bits/stdc++.h>
#define ll long long
// // #define pb push_back
// // #define fr(a,b) for(int i = a; i < b; i++)
// // #define repA(i,a,b) for(int i = a; i < b; i++)
// // #define rep(i,n) for(int i = 0; i < n; i++)
// // #define mod 1000000007
// // #define inf (1LL<<60)
// // #define all(x) (x).begin(), (x).end()
// // #define prDouble(x) cout << fixed << setprecision(10) << x
// // #define triplet pair<ll,pair<ll,ll>>
// // #define goog(tno) cout << "Case #" << tno <<": "
// #define fast_io                       \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)
// #define read(x) int x; cin >> x
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
     int n;
     cin>>n;
     int arr[n+1],out[n+1];
     for(int i=1;i<=n;i++){
         cin>>arr[i];
         out[i] = 0;
     }
     out[1] = 1;
     for(int i=2;i<=n;i++){
         for(int j=i+1;j<=n;j++){
             if(arr[j] > arr[i]){
                 int temp = arr[j];
                 arr[j] = arr[i];
                 arr[i] = temp; 
             }
         }
         out[i] = arr[i]; 
     }
     for(int i=1;i<=n;i++){
         cout<<out[i]<<"\t";
     }
     cout<<"\n";
    }
    return 0;
}
