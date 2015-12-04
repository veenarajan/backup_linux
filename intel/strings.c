#include <stdio.h>
#include <string.h>

int main()
{
	// substring / subsequqnc 
	
	char buf[50] = "radar";
	char s[20] = "rAj";
	int i;
	int j=0;
	int count =0;
	for (i = 0; i < strlen(buf); i++)
	{
		if(s[j]!='\0')
		{
			if (buf[i] == s[j])
			{
				j++;
			}
		}
	}
	if (j==strlen(s))
	{
		printf("yoo\n");
	}


	// convert to upper case

	for (i = 0; i < strlen(buf); i++)
	{
		if (buf[i] == ' ')
		{
			continue;
		}
		else
		    *(buf+i) -= 32;
	}

	printf("%s\n", buf);

	// reverse

	for (i = 0,j = strlen(buf)-1; j>=0; i++,j--)
	{
		//printf("%c\n", buf[j]);
		s[i] = buf[j];
	}
	s[i] = '\0';

	printf("%s\n", s);


	//palindrome

	for (i = 0; i < strlen(buf)/2; i++)
	{
		if (buf[i] == buf[strlen(buf) - 1-i])
		{
			count++;
		}
	}

	if (count == strlen(buf)/2)
	{
		printf("lll\n");
	}


    //sort a sting

    for (i = 0; i < strlen(buf) - 1; i++)
    {
    	for (j = i; j < strlen(buf); j++)
    	{
    		if (buf[i]> buf[j])
    		{
    			char temp = buf[i];
    			buf[i] = buf[j];
    			buf[j] = temp;
    		}
    	}
    }

    printf("%s\n", buf);

    printf("%s\n",strev(buf) );



}


