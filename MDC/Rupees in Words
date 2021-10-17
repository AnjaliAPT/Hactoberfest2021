#include <stdio.h>
#include<string.h>
void convert(char *num)
{
    int len=strlen(num);
  const char *a[]={"Zero","one","two","three","four","five","six","seven","eight","nine"};
  const char *b[]={"","ten","eleven","twelve","thirteeen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
  const char *c[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninty"};
  const char *d[]={"hundred","thousand"};
   if(len==1){
       printf("%s\n",a[*num-'0']);
       return;
   }
   while(*num !='\0'){
       if(len>=3){
           if(*num-'0'!=0){
               printf("%s ",a[*num-'0']);
               printf("%s ",d[len-3]);
           }
           --len;
       }
   else{
       if(*num=='1'){
           int sum=*num-'0'+*(num+1)-'0';
           printf("%s\n",b[sum]);
       return;
   }
   else if(*num=='2'&& *(num+1)=='0'){
       printf("twenty\n");
       return;
   }
   else{
       int i=*num-'0';
       printf("%s ",i?c[i]:"");
       ++num;
       if(*num!='0')
       printf("%s ",a[*num-'0']);
   }
   
}
++num;
}
}
int main()
{
    char a[10];
    scanf("%s",a);
    convert(a);
	return 0;
}
