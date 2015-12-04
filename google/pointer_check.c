//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
using namesapce std;

int divide(int a , int b)
{
	return a/b;
}

double divide(double a, double b)
{
	return a/b;
}

int main()
{
	//char *p = "Linux";
	//printf("%c", *p);
	//printf("%c", *p++);
	//printf("%c", *p);
	int a = 10;
	int b = 5;
	int c = divide(a,b);
	cout<<c;

	double e = 22.0;
	double f = 11.0;
	double g = divide(e,f);

	cout<<g;

	int h = divide(e,f);
	cout<<h;
	return 0;
}