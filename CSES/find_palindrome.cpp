//given string is palindrome or not
#include<iostream>
using namespace std;
int main()
	{
        int l,j,i;
        cout<<"length of string:"; //calculate length of string
        cin>>l;
        string pl[l];
        for(i=0;i<l;i++){
            cin>>pl[i]; //input of string char by char
        }
        j=l-1;
        for(i=0;i<(l/2);i++)
        {
            if(pl[i]==pl[j])
               {           j--;
               }
        }
        if(j == (l-i-1))
        {
            cout<<"the given string is palindrome"<<endl;
        }
        else
        {
            cout<<"the given string is not palindrome"<<endl;
        }
		cout<<pl<<endl; //showing the result
		return 0;
	}