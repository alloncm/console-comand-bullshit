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
	void Add(const char* name,int val);			//adds another Entry to the database
	void Save(char* filename,Database& l);		//saves the data base to a specicfic .txt file and wipes the data base 
	void Load(char* filename);					//load the enrties from a .txt file
	void Print();								//prints the Database
};