// Question-Maximum Profit on App

// You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.
// You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit that you can earn.
// Lets say you decide that price of your app is Rs. x and there are N number of subscribers. So maximum profit you can earn is :
//  m * x
// where m is total number of subscribers whose budget is greater than or equal to x.

//Solution-
  
  #include <iostream>
using namespace std;


void merge(int input[], int si,int ei){
	
    if(si>=ei){
        return;
    }
    int mid=((si+ei)/2);
    merge(input,si,mid);
    merge(input,mid+1,ei);
    
    int i=si,j=mid+1,k=si;
    int temp[99999];
    while(k<=ei){
        if(i<=mid&&j<=ei){
            if(input[i]<=input[j]){
                temp[k]=input[i];
                i++;
                k++;
            }
           else if(input[i]>input[j]){
                temp[k]=input[j];
                j++;
                k++;
            }
        }
        else if(i>mid){
            temp[k]=input[j];
                j++;
            k++;
        }
        else if(j>ei){
             temp[k]=input[i];
                i++;
            k++;
        }
    }
    for(k=si;k<=ei;k++){
        input[k]=temp[k];
    }
    
}

int maximumProfit(int budget[], int n) {
    // Write your code here
     int max=0,j=n;
         merge (budget,0,n-1);
    for(int i=0;i<n;i++){
        int temp=budget[i]*j;
        j--;
        if(temp>max){
            max=temp;
        }
    }
    return max;
}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
