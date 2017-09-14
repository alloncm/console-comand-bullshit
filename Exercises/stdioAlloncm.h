#pragma once
#include<stdio.h>
namespace alloncm
{
	int pow(int a, int n);

	int str2int(const char* str);

	void GetStr(char* buf, int size);

	int GetFibonachiPlace(int a);

	void int2str(int num, char* buf);

	void print(const char* str);
	
	void ReverseStr(char* str);
}