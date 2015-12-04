#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//using namespace std;

int main() {
	char *s = "aaaaaaaaaaaa bbbbbbbbbbb ccccccccccc\0";
	//vector<string> vec;
	int i = 0;
	char *buf = (char*) malloc(sizeof(char)*500);
	int start = 0;
	int count  = 0;
	int j = 0;
	//printf("%c\n", *s);
	while(*s !='\0')
	{
		if (*s == '\0')
		{
			break;
		}
		i = 0;
	    while(s[i] != ' ')
	    	i++;

	    printf("after i %c\n", *s);
	    count  = i +1;
	    start = 0;
	    printf("count%d\n", count);
	    while(i--)
	    {
	    	buf[j] = s[start];
	    	j++;
	    	start++;
	    }
	    
	    printf("%d\n", i);
	    while(count--)
	    	*s++;

	    printf("bufff %s\n", buf);
	    printf("strrr %s\n", s);
	   


	   //printf("%s\n", s);
	   
	}
	
	//for(int i = 0;i<(int)vec.size(); i++)
	//{
	  //  cout<<vec[i]<<endl;
//	}
	
	return 0;
}
