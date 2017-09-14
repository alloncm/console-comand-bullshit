#include "stdioAlloncm.h"

int alloncm::pow(int a, int n)
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

int alloncm::str2int(const char* str)
{
	/*
	int place = 0;
	const char* p = str;
	for (; *str != 0; str++)
	{
		place++;
	}
	int num = 0;
	place--;
	for (; p < str; p++, place--)
	{
		num += (*p - '0')*pow(10, place);

	}
	return num;
	*/
	int number = 0;
	for (; *str <= '9'&&*str >= '0'; str++)
	{
		number *= 10;
		number += *str - '0';
	}
	return number;
}

void alloncm::GetStr(char* buf, int size)
{
	int i = 0;
	while (i < size - 1 && buf[i - 1] != '\n')
	{
		buf[i] = getc(stdin);
		i++;
	}
	buf[i - 1] = '\0';
}

int alloncm::GetFibonachiPlace(int a)
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

void alloncm::int2str(int num, char* buf)
{
	/*
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
	*/
	int a = num;
	int i = 0;
	while (a > 10)
	{
		buf[i] = a % 10 + '0';
		a /= 10;
		i++;
	}
	buf[i] = a+'0';
	buf[i+1] = '\0';
	ReverseStr(buf);
	//alloncm::print(buf);
}

void alloncm::print(const char* str)
{
	int i = 0;
	while (str[i] != 0)
	{
		putchar(str[i]);
		i++;
	}
}

void alloncm::ReverseStr(char * str)
{
	int i = 0;
	char * t = str;
	for (; *t != 0; t++)
	{
		i++;
	}
	int size = i;
	i--;
	for (int j = 0; j < size / 2; j++,i--)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	/*
	int j = 0;
	str--;
	for (j = 0; j < i; j++,str--)
	{
		buf[j] = *str;
	}
	buf[i] = '\0';
	for (j = 0;j < i; j++)
	{
		str[j] = buf[j];
	}
	str[i] = '\0';
	*/
}
