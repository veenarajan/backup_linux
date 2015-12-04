#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct box {
	char *src;
	char *dest;

};
struct check
{
	char *city;
	int value;
};

int isPresent(struct check ptr[], char* dest)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		int k = strcmp(ptr[i].city, dest);
		if(k==0)
		{	
			return 1;
		}
	}

	return 0;
	
}
int main()
{
	struct box b[4];
	
	struct check ptr[8];

	b[0].src = "bombay";
	b[0].dest = "goa";

	b[1].src = "goa";
	b[1].dest = "delhi";
	
	b[2].src = "delhi";
	b[2].dest = "nagpur";
	
	b[3].src = "nagpur";
	b[3].dest = "chennai";

	int i=0;
	for (i = 0; i < 4; i++)
	{
		ptr[i].city = b[i].src;
		if (isPresent(ptr, b[i].dest))
		{
			ptr[i].value = 0;
		}
		else
		{
			printf("not pressnt \n");
		}	
	}

	//printf("%s\n", ptr[0].city);


	return 0;
}



// from the map create a linked list which has a strcut object isntead of int .. having < name and int value>
// for every value of the ticket in the soruce add it to the linked list if not present and init to a value of -1;
// if it comes as a part of the list then make the vakue 0
// the elements with vakue -1 will be the ones that do not are souece and destination
// add at head to reduce cmplexoty of travelsal
