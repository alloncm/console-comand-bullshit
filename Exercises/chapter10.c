/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//prototipes
char* getString(char*, size_t, char);
void show(double[], int, int);


char* getString(char* buffer, size_t buf, char end)
{
	char* temp = NULL;
	char cur = 0;
	int len = strlen(buffer);
	while ((cur = getchar()) != end)
	{
		if (len == buf - 1)
		{
			printf("error\n ");
			return NULL;
		}
		*(buffer + len) = cur;
		len++;
	}
	*(buffer + len) = '\0';
	return buffer;
}
int main(void)
{
	//checking getString exr4
	char* s = (char*)malloc(20);
	s[0] = '\0';
	char* temp;
	if ((temp = getString(s, 20, '.')))
	{
		printf("succes %s\n", temp);
	}
	else
	{
		printf("NULL \n");
	}
	//finish

	//checking show exr3
	double d[] = { 1.56768, 1.8, 2.1, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.2, 4.5 };
	show(d, 11, 12);
	//finish

	//exr2
	fflush(stdin);
	int i = 0;
	double total = 0;
	double cur = 0;
	printf("\nenter 3 floating pionts values\n");
	for (i = 0; i < 3; i++)
	{
		scanf_s("%*[ ,$] %lf", &cur);
		total += cur;
	}
	printf("total= %lf\n",total);

	return 0;
}
void show(double d[], int size, int width)
{
	int i = 0;
	int w = 1;
	for (i = 0; i < size; i++)
	{
		printf("%12.2lf ",d[i]);
		if (w == 5)
		{
			printf("\n");
			w = 0;
		}
		w++;
	}
}
*/