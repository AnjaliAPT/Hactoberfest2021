class Solution
{
    public:
    int findPeakUtil(int arr[], int low, int high, int n)
    {
        // calculating mid
        int mid = (low+high)>>1;
        
        // if mid is last or first index with first element
        // greater than next.
        // Also, check if mid element is greater than mid - 1 and mid+1
        if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
                (mid == n-1 || arr[mid+1] <= arr[mid]))
            return mid;
            
        // If mid is other than 0, then check if mid element is less than prev.
        // If so, then recurse for lower half
        else if (mid > 0 && arr[mid-1] > arr[mid])
            return findPeakUtil(arr, low, (mid -1), n);
            
        // else recurse for the upper half
        else return findPeakUtil(arr, (mid + 1), high, n);
    }
    
    public:
    int peakElement(int arr[], int n)
    {
        return findPeakUtil(arr, 0, n-1, n);
    }
};
