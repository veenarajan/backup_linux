#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strcmpp(const char* str1, const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int a = abs(len1 - len2);

	while(a)
	{
		if(len1 > len2)
		{
			if(*str1!='\0')
			{
				if (*str1 == ' ')
				{
					str1++;
				}
					
			}
		}
		else
		{
			if(*str2!='\0')
			{
				if (*str2 == ' ')
				{
					str2++;
				}
			}
		}

		a--;
	}

	int i = 0;
	printf("%d %s\n", (int)strlen(str1), str1);
	printf("%d %s\n",(int) strlen(str2), str2);

	int up_1 = strlen(str1);
	int up_2 = strlen(str2);

	if (up_2 != up_1)
	{
		return -1;
	}

	while(up_1)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			i++;
		}

		up_1--;
	}

	
	if (i == up_2)
	{
		return 0;
	}

	//return 0;
	
}

int main(int argc, char const *argv[])
{
	char* s = "aaa";
	char* c = "  aab";

	printf("%d\n", strcmpp(s,c));
	return 0;
}