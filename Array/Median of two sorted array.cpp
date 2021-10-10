class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n=array1.size();
        int m=array2.size();
        
        if(n>m)
        {
             return MedianOfArrays(array2, array1); 
             //swapping for smaller array
        }
        
        int low=0;
        int high=n; 
        //in veirtual set we can choose from 0 to n elements from arr1
        
        while(low<=high)
        {
            int mid1=(low+high)>>1;
            int mid2=(m+n+1)/2-mid1;
            
            
            int max1=(mid1==0?INT_MIN:array1[mid1-1]);
            int min1=(mid1==n?INT_MAX:array1[mid1]);
            int max2=(mid2==0?INT_MIN:array2[mid2-1]);
            int min2=(mid2==m?INT_MAX:array2[mid2]);
            // to cut corner cases where no elements are selected
            // either from left side or from extreme righ sides
            
            if(max1<=min2 && max2<=min1)
            {
                if((n+m)%2==0)
                    return (max(max1,max2)+min(min1,min2))/2.0;
                else
                    return max(max1,max2);
            }    
            // returning median if verified set
            
            else if(max1>min2)
                    high=mid1-1;
            else
                low=mid1+1;
            
        }
        
        return 0.0;
    
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}
