#include<iostream>
using namespace std;
int maxSumSubarray(int array[],int length) {
   int highestMax = 0;
   int presentMax = 0;
   for(int i = 0; i < length; i++){
      presentMax =max(array[i],presentMax + array[i]) ;
      highestMax = max(highestMax,presentMax);
   }
   return highestMax;
}
int main() {
   int array[7]={3, -5, 4, -1, -2, 6, -8};
   cout << "The Maximum Sum is: "<<maxSumSubarray(array,sizeof(array)/sizeof(array[0])) << endl;
   return 0;
}