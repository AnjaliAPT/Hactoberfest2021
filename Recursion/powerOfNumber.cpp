#include<iostream>
using namespace std;

long long int power(long int x,long int n){
    // base case
    if(n==0){
        return 1;
    }

    // recursive case
    return x*power(x,n-1);
}

int main(){
    long int x,n;
    cin>>x>>n;

    cout<<power(x,n)<<endl;

    return 0;
}