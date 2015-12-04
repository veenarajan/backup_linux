#include <stdio.h>
#include <stdlib.h>

void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    int i;
    for (i = cur; i > outofplace; i--)
        arr[i] = arr[i-1];
    arr[outofplace] = tmp;
}


void rearrange(int arr[], int n)
{
    int outofplace = -1;
    int index = 0;
 
    for (index = 0; index < n; index ++)
    {
        if (outofplace >= 0)
        {
            // find the item which must be moved into the out-of-place
            // entry if out-of-place entry is positive and current
            // entry is negative OR if out-of-place entry is negative
            // and current entry is negative then right rotate
            //
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4, -5...]
            //      ^                          ^
            //      |                          |
            //     outofplace      -->      outofplace
            //
            if (((arr[index] >= 0) && (arr[outofplace] < 0))
                || ((arr[index] < 0) && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);
 
                // the new out-of-place entry is now 2 steps ahead
                if (index - outofplace > 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
 
 
        // if no entry has been flagged out-of-place
        if (outofplace == -1)
        {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01)))
            {
                outofplace = index;
            }
        }
    }
}


int main()
{
    int a[] = {1,2,3,-1,-2,-3,4,5,6,-7,-8,-9,12,31};
    int n = sizeof(a)/sizeof(a[0]);
    rearrange(a, n);

    int i=0;
    for(i=0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}