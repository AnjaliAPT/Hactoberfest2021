#include<iostream>
using namespace std;

int main()
{

    const int max=100;
    int arr[max];
    int size=0,arr_index_delete,element_delete,pos=-1;
    int opt;

    for(int i=0; i<max; i++)
    {
        if((i%5)==0&&i!=0)
        {       popup:

                cout<<"\nWant to add more element :: (type 1 for yes or type 2 for no) :";
                cin>>opt;
                cout<<endl;
                if(opt==1)
                {
                    goto add_more_elements;
                }
                else if(opt==2)
                {
                    break;
                }
                else if((opt!=1)||(opt!=2))
                {
                    cout<<"!!!!!!!!!!! You have entered incorrect input !!!!!!!!!!!!!\n";
                    goto popup;
                }

        }
        add_more_elements:
        cout<<"Enter the element no. "<<(i+1)<<"  : ";
        cin>>arr[i];
        size=size+1;
;    }

    cout<<"Enter the element no you want to delete";
    cin>>element_delete;
    arr_index_delete=element_delete-1;


    for(int i=0;i<max;i++)
    {
        if(arr[i]==arr[arr_index_delete])
        {
            pos=i;
            break;
        }
    }

    if(pos!=-1)
    {
        for(int i=pos; i<max; i++)
        {
            arr[i]=arr[i+1];
        }
        size-=1;
    }
    cout<<"\n##########################################################################\n";
	for(int i=0; i<size; i++)
	{
	     cout<<"Element no. "<<i+1<<" is "<<arr[i]<<'\n';
	}
	cout<<"############################################################################\n";
    return 0;
    }






