#include <stdio.h>
#include <stdlib.h>
int n;
void Traverse(int arr[])
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
}
void LinearSearch(int *arr,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(key==arr[i])
           {
               printf("\nElement Found at Index %d\n",i+1);
               break;
            }
        else if(i==n &&key!=arr[i])
            printf("Element Not Found\n");
    }
}
int BinarySearch(int *arr,int key,int l,int h)
{
    int mid;
    if(l>h)
    {
         printf("Element not Found\n");
         return 0;
    }
     mid=(h+l)/2;
    if(arr[mid]!=key)
    {
        if(key>arr[mid])
            return BinarySearch(arr,key,mid+1,h);
        else if(key<arr[mid])
            return BinarySearch(arr,key,l,mid-1);
    }
    else return mid;
}
void insertion(int *arr,int ele,int pos)
{ int i;
    for(i=n;i>=pos;i--)
        arr[i]=arr[i-1];
    arr[pos]=ele;
}
void updation(int *arr,int key,int pos)
{
    arr[pos]=key;
}
void specialUpdation(int *arr,int key,int pos)
{
    int i,temp;
    arr[pos]=key;
    if(arr[pos]>arr[pos+1])
       {for(i=pos;i<n;i++)
        if(arr[i]>arr[i+1])
            {  temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
    else if(arr[pos]<arr[pos-1])
            {
                   for(i=pos;i>=0;i--)
               {
                   if(arr[pos]<arr[i-1])
                       {  temp=arr[i];
                           arr[i]=arr[i-1];
                           arr[i-1]=temp;
                        }
                }
            }
}
void delete(int *arr,int key)
{ int i;
    for(i=0;i<n;i++)
       {
           if(key==arr[i])
           {
                printf("Deleted element is %d\n",arr[i]);
                arr[i]=-1;
           }
       }
}
int main()
{  int i,ch,key,pos;
    printf("Enter size of Array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    do
    {
        printf("\nPress 1 to Traverse and Display Array\n");
        printf("Press 2 to do Linear Search\n");
        printf("Caution!! Binary Search can Only applied on Sorted Data\nPress 3 to do Binary Search\n");
        printf("Press 4 to Insert Element at required position\n");
        printf("Press 5 to do Updtion\n");
        printf("Press 6 to do Special Update for sorted elements\n");
        printf("Press 7 to do Deletion");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:Traverse(arr);
                        break;
            case 2: printf("Enter Element to search\n");
                         scanf("%d",&key);
                         LinearSearch(arr,key);
                         break;
            case 3: printf("Enter Element to search\n");
                         scanf("%d",&key);
                         if(BinarySearch(arr,key,0,n))
                             printf("Element Found at Index %d\n",BinarySearch(arr,key,0,n)+1);
                        break;
            case 4: printf("Enter element and its position\n");
                         scanf("%d%d",&key,&pos);
                         insertion(arr,key,pos);
                         break;
            case 5: printf("Enter position to Update and enter Element\n");
                         scanf("%d%d",&pos,&key);
                         updation(arr,key,pos);
                         break;
            case 6: printf("Enter position to Update and enter Element\n");
                         scanf("%d%d",&pos,&key);
                         specialUpdation(arr,key,pos);
                         break;
            case 7: printf("Enter Element to Delete\n");
                         scanf("%d",&key);
                         delete(arr,key);
                         break;
        }
    }while(ch<8);
    return 0;
}
