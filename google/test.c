#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* rle(char* a)
{
    int len  = strlen(a);
    char* r = (char*)malloc(sizeof(char) * len * 2 );
    int p[26] = {0};
    int i = 0;
    int j = 0;
    for(i = 0 ; i<strlen(a); i++)
    {
        p[a[i] - 'A']++;
    }
    
    for(i =0;i<26;i++)
    	printf("%d\n", p[i]);
    
   for(i = 0; i< 26 ;i++)
    {
        if(p[i]!=0)
        {
            r[j] = (char)(i+'A');
            r[j+1] = (char)(p[i] + '0');
            j = j+2;
            
        }
    }
    r[j] = '\0';
    
    return r;
}
int main(void) 
{
	char* a = "AAAADDDBBCCAA";
    char* p = rle(a);
    
    printf("%s",p);
	
	return 0;
}

