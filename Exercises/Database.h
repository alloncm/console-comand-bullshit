#pragma once
#include"stdioAlloncm.h"
#include<fstream>

class Database
{
private:
	class Entry
	{
	private:
		static constexpr int nameLenght = 10;
		char name[nameLenght];
		int value;
	public:
		Entry() = default;
		Entry(const char* n, int val);
		void SetName(char* n);
		void SetValue(int v);
		const char* GetName();
		int GetValue();
		void print();
	};
private:
	static constexpr int maxDatabaseMembers = 16;
	Entry Data[maxDatabaseMembers];
	int current = 0;
public:
	Database() = default;
	void Add(const char* name,int val);
	void Save(char* filename);
	void Load(char* filename);
	void Print();
};