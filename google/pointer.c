#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	const char *p = "veena";
	char * const a = "suchitra";

	char *b = "sunder";

	//strcpy(p,b);

	//strcpy(a,b);
	printf("%s\n", b);

	printf("%s\n", a);


	int x = 0x1234;
	char s = (char)x;

	printf("%x\n", s);

	printf("%d\n", 7/5);
	printf("%lf\n", 7/5.0);
	return 0;
}