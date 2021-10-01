
// Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.
// https : //www.geeksforgeeks.org/array-rotation/

#include <stdio.h>
//#include <conio.h>
void rotate(int[], int, int);
int gcd(int, int);

int main()
{
    int n, d, i;
    printf("Enter the size of array ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the left rotation number ");
    scanf("%d", &d);

    rotate(a, n, d);

    printf("Array after rotation is\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

void rotate(int a[], int n, int d)
{
    int i, j, k, temp;
    int g = gcd(n, d);

    for(i = 0; i < g; i++)
    {
        temp = a[i];
        j = i;

        while(1)
        {
            k = j + d;
            if(k >= n)
                k = k - n;
            if(k == i)
                break;

            a[j] = a[k];
            j = k;
        }
        a[j] = temp;
    }
}

int gcd(int p, int q)
{
    if(q == 0)
        return p;
    else
        return(gcd(q, p % q));
}
