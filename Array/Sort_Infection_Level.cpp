#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int x,y;
    int r=0;
    for(int i=n-1;i>0;i--)
    {
        if(arr[i]>arr[i-1])
        {
            x=i;
            r=1;
            break;
        }
    }

   if(r==1)
   {
       for(int i =0;i<x;i++)
       {
            if(arr[i]<arr[i+1])
            {
                y=i;
                break;
            }
        }


        int t;
        t=arr[x];
        arr[x]=arr[y];
        arr[y]=t;
 
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }
    else
        cout<<"No swapping needed";

    return 0;
}
