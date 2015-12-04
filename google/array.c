#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	int c[15];

	int i=0;
	int j=0;
	int k=0;

	while((i<5) && (j<10))
	{
		if (a[i]<=b[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}
		else if (a[i]> b[j])
		{
			c[k] = b[j];
			j++;
			k++
		}
	}

	if (i<5)
	{
		while(i<5)
		{
			c[k] = a[i];
			i++;
			k++;	
		}
	}

	if (j<15)
	{
		while(j<15)
		{
			c[k] = b[j];
			i++;
			k++;	
		}
	}

	for (i = 0; i < 15; i++)
	{
		/* code */
	}



}