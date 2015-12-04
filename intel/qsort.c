#include <stdio.h>

void quicksort(int x[],int first,int last)
{
    int pivot,j,temp,i;
    int k;

    // 0 size-1
    // O(n2) time complexity 

    if(first<last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i<j)
        {
            while(x[i]<=x[pivot] && i<last)
                i++;
            
            while(x[j] > x[pivot])
                j--;
            
            if(i<j)
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }

        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        
		    quicksort(x,first,j-1);
        quicksort(x,j+1,last);

    }
}

int main()
{
  int x[7] = {7,8,6,5,1,2,3};
  int size,i;

  size = sizeof(x)/sizeof(x[0]);

  quicksort(x,0,size-1);

  printf("Sorted elements: ");
  
  for(i=0;i<size;i++)
    printf(" %d",x[i]);

  return 0;
}


void quicksort( int a[], int low, int high )
{
 int pivot;

 // Termination condition! 
 
 if ( high > low )
 {
  
  pivot = partition( a, low, high );
  quicksort( a, low, pivot-1 );
  quicksort( a, pivot+1, high );
 
 }
} 

//end quicksort


int partition( int a[], int low, int high )
{
 int left, right;
 int pivot_item;
 int pivot = left = low;
 // forst element is pivot

 pivot_item = a[low]; 
 
 right = high;

 // last is high
 
 while ( left < right ) 
 {
  
  // Move left while item < pivot 
  
  while( a[left] <= pivot_item && left<high) 
   left++;
  
  // Move right while item > pivot 
  while( a[right] > pivot_item ) 
   right--;
  
  if ( left < right ) 
   swap(a,left,right);
 }
 // right is final position for the pivot 
 a[low] = a[right];
 a[right] = pivot_item;
 return right;
}