#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *fileStream_1,*fileStream_2,*fileStream_3, *f;
	char buffer[10];
	char s[10];
	fileStream_1 = fopen("first", "r");
	fileStream_2 = fopen("second", "r");
	fileStream_3 = fopen("merge", "w+");

	fseek(fileStream_1, 0L, SEEK_END);
	int size_1 = ftell(fileStream_1);
	rewind(fileStream_1);
	fseek(fileStream_2, 0L, SEEK_END);
	int size_2 = ftell(fileStream_2);
	rewind(fileStream_2);

	f = size_1 > size_2 ? fileStream_1 : fileStream_2;
	
	
	while(1)
	{
		
		fscanf(fileStream_1, "%s", buffer);
		fscanf(fileStream_2, "%s", s);
		printf("%d\n", strcmp(buffer,s));

		if (strcmp(buffer, s) == 0)
		{
			fprintf(fileStream_3, "%s\n", buffer);
		}
		else if(strcmp(buffer, s)  > 0)
		{
			fprintf(fileStream_3, "%s\n", s);
			fprintf(fileStream_3, "%s\n", buffer);	
		}
		else if(strcmp(buffer, s) < 0)
		{
			fprintf(fileStream_3, "%s\n", buffer);
			fprintf(fileStream_3, "%s\n", s);	
		}

		sleep(1);

		if (!feof(f))
		{
			break;
		}


	}


	if (!feof(fileStream_1))
	{
		while(1)
		{
			fscanf(fileStream_1, "%s", buffer);
			fprintf(fileStream_3, "%s\n", buffer);
			if (!feof(fileStream_1))
			{
				break;
			}

		}
	}


	if (!feof(fileStream_2))
	{
		while(1)
		{
			fscanf(fileStream_2, "%s", s);
			fprintf(fileStream_3, "%s\n", s);

		

		if (!feof(fileStream_2))
			{
				break;
			}
		}
	}
	
	fclose(fileStream_1);
	fclose(fileStream_2);
	
	//printf("%s\n", buffer);
	//printf("%s\n", s);



	fclose(fileStream_3);


	return 0;
}