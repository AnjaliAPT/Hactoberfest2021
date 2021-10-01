#include <bits/stdc++.h>

using namespace std;

int maxConsecutiveOne(int arr[], int n){
    int res = 0,count =0;
    for(int i=0 ; i<n ; i++){
            if(arr[i] != 1){
                 count = 0;
            }
            else{
                    count++;
             res = max(res , count);
            }
    }
    return res;
 }

int main()
{
     int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    cout<<maxConsecutiveOne(arr , n);

    return 0;
}
