#include <stdio.h>
#include <stdlib.h>

int power(int base, int e)
{
  if (e == 0)
  {
    return 1;
  }
  else
  {
    return base * power(base, e-1);
  }
}
int main()
{
	int n = 10;
	int i = 0;
	int j = 0;
	int count = 0;
	int start = 3;
	
  printf("2 \t");
	
  for ( i = 2 ; i <= n ;  )
  {
    
    for ( j = 2 ; j <= start - 1 ; j++ )
    {
      if ( start%j == 0 )
        break;
    }
    
    if ( j == start )
    {
      printf("%d\n",start);
      i++;
    }
      	
    start++;
  }
	
  printf("%d\n", power(2,1));
  return 0;
}