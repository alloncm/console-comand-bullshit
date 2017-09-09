#include<stdio.h>

int pow(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return a;
	}
	return pow(a*a, n - 1);
}

int str2int(const char* str)
{
	int place = 0;
	const char* p = str;
	for (; *str != 0; str++)
	{
		place++;
	}
	int num = 0;
	place--;
	for (; p < str; p++,place--)
	{
		num += (*p-'0')*pow(10, place);

	}
	return num;
}

void GetStr(char* buf,int size)
{
	int i = 0;
	
	while (i < size - 1 && buf[i-1] != '\n'  )
	{
		buf[i] = getchar();
		i++;
	}
	buf[i-1] = '\0';
}

int GetFibonachiPlace(int a)
{
	if (a == 1 || a == 2)
	{
		return 1;
	}
	int first = 1;
	int second = 1;
	int i = 3;
	for (i; i <= a; i++)
	{
		int b = second;
		second += first;
		first = b;
	}
	return second;
}

void int2str(int num, char* buf)
{
	int size = 1;
	int a = num;
	while (a / 10 != 0)
	{
		a /= 10;
		size++;
	}
	int i = 0;
	for (i; i < size; i++)
	{
		buf[i] = num / pow(10, size - i - 1);
		num -= buf[i] * pow(10, size - i - 1);
		buf[i] += '0';
	}
	buf[i] = '\0';
}

void print(const char* str)
{
	int i = 0;
	while (str[i] != 0)
	{
		putchar(str[i]);
		i++;
	}
}
int main()
{
	const int size = 10;
	char str[size];
	GetStr(str, size);
	int number = str2int(str);
	long long fib = GetFibonachiPlace(number);
	int2str(fib, str);
	print(str);
	char a=65;
	print("press 0 to exit");
	while ( a != '0')
	{
		a = getchar();
		fflush(stdin);
	}
	return 0;
}