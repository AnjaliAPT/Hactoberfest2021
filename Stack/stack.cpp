/* Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

*/


#include<bits/stdc++.h>
using namespace std;

bool check(string str){
	stack<char>s;
	for(int i=0;i<str.size();i++){
		if(str[i]=='(' || str[i]=='*'|| str[i]=='/' || str[i]=='+' || str[i]=='-'){
			s.push(str[i]);
		}
		else if(str[i]==')'){
			if(s.top()=='('){
				return false;
			}
			else{
				while(!s.empty() && s.top()!='('){
					s.pop();
				}
				s.pop();
			}
		}
	}
	return true;
}

int main(){
	string str;
	cout<<"Enter the string ";
	cin>>str;
	bool status=check(str);
	if(status){
		cout<<"No redundant brackets";
	}
	else{
		cout<<"Redundant brackets are present";
	}
}
