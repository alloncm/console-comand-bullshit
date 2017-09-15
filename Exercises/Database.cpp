#include "Database.h"

void Database::Add(const char* n, int val)
//adds another entry
{
	Data[current] = Entry(n, val);
	current++;
}

void Database::Save(char * filename,Database& l)
//saves the database to a .txt file and wipes the Database
{
	std::ofstream out(filename,std::ios::app);

	for (int i = 0; i < current; i++)
	{
		const char* str = Data[i].GetName();
		for (; *str != 0; str++)
		{
			out.put(*str);
		}
		int val = Data[i].GetValue();
		out.put(':');
		char instr[10];
		alloncm::int2str(val, instr);
		for (int g=0;instr[g]!=0;g++)
		{
			out.put(instr[g]);
		}
		out.put('\n');
		l.Add(Data[i].GetName(), Data[i].GetValue());
	}
	this->current = 0;
}

void Database::Load(char * filename)
{
	std::ifstream in(filename);
	if (!in.good())
	{
		alloncm::print("an error has happend cannot open the file: ");
		alloncm::print(filename);
		alloncm::print("\n");
	}
	char p = 0;
	char str[10];
	char ins[10];
	p = in.peek();
	while (p != EOF)
	{
		int i = 0;
		for (i = 0; str[i] = in.get(), str[i] != ':'; i++);
		str[i] = '\0';
		for (i = 0; ins[i] = in.get(), ins[i] != '\n'; i++);
		ins[i] = '\0';
		int val = alloncm::str2int(ins);
		Add(str, val);
		p = in.peek();
	}
}

void Database::Print()
{
	for (int i = 0; i < current; i++)
	{
		Data[i].print();
	}
}

Database::Entry::Entry(const char * n, int val)
	:
	value(val)
{	
	int i = 0;
	for (; *n != 0; n++, i++)
	{
		name[i] = *n;
	}
	name[i] = '\0';
}

void Database::Entry::SetName(char * n)
{
	int i = 0;
	for (; *n != 0; n++, i++)
	{
		name[i] = *n;
	}
	name[i] = '\0';
}

void Database::Entry::SetValue(int v)
{
	value = v;
}

const char * Database::Entry::GetName()
{
	return name;
}

int Database::Entry::GetValue()
{
	return value;
}

void Database::Entry::print()
{
	alloncm::print(name);
	alloncm::print("\n");
	char buf[10];
	alloncm::int2str(value, buf);
	alloncm::print(buf);
	alloncm::print("\n");
}
