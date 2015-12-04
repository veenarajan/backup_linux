#include <stdio.h>
 
int main()
{
   int array[6] = {9,8,7,6,5,4};
    
   int n, c, d, position, swap;
   
   n = 6; 
   
   // 0 to n-1
   //min = 0

   //loop from 1 to n
   // if a[0] > a[1..n]
   // update min index ... and it will r=take the value of the lowest number
   //
   // check for the index...
   // if is different then swap else retain
   

   for ( c = 0 ; c < ( n - 1 ) ; c++ )
   {
      position = c;
 
      for ( d = c + 1 ; d < n ; d++ )
      {
         if ( array[position] > array[d] )
            position = d;
      }
      if ( position != c )
      {
         swap = array[c];
         array[c] = array[position];
         array[position] = swap;
      }
   }
 
   printf("Sorted list in ascending order:\n");
 
   for ( c = 0 ; c < n ; c++ )
      printf("%d\n", array[c]);
 
   return 0;
}