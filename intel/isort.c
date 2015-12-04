/* insertion sort asiending order */
 
#include <stdio.h>
 
int main()
{
  int n;
  int array[]= {9,8,7,6,5,4};
  int i, d, temp;
 
 
  //loop form 1 to n-1
  //set index as d =1
  //
  // if a[d] < a[1]
  // swap and dec d till d>0

  for (i = 1 ; i <= n - 1; i++) 
  {
    d = i;
 
    while ( d > 0 && array[d] < array[d-1]) 
    {
      temp          = array[d];
      array[d]   = array[d-1];
      array[d-1] = temp;
 
      d--;
    }
  }
 
  printf("Sorted list in ascending order:\n");
 
  for (i = 0; i <= n - 1; i++) {
    printf("%d\n", array[i]);
  }
 
  return 0;
}