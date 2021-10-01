#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    int n;
    //input
    cin>>n;
    int x;
    //entering array elements
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        vec.push_back(x);
    }

    int counter=1;
    while (counter<n)
    {
        for(int i=0;i<n-counter;i++){
            if(vec[i]>vec[i+1]){
                int temp=vec[i];
                vec[i]=vec[i+1];
                vec[i+1]=temp;
            }
        }
        counter++;
    }

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        cout << *i << " ";
    }

    return 0;
}
