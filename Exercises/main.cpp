
#include"Database.h"

using namespace alloncm;

void usingDb()
{
	char c = 0;
	Database newData;
	Database loadData;
	while (c != 'e')
	{
		print("(l)oad (s)ave (a)dd (p)rint or (e)xit?\n");
		char a = getchar();
		getchar();
		int b;
		switch (a)
		{
		case 'l':
			loadData.Load("derp.txt");
			print("load complete\n");
			break;
		case 's':
			newData.Save("derp.txt", loadData);
			print("save complete\n");
			break;
		case 'a':
			print("enter a name\n");
			char buf[10];
			GetStr(buf, 10);
			char instr[10];
			print("enter a number\n");
			GetStr(instr, 10);
			b = str2int(instr);
			newData.Add(buf, b);
			break;
		case 'p':
			loadData.Print();
			newData.Print();
			break;
		case 'e':
			c = a;
			break;
		}
	}
}
int main()
{
	
	return 0;
}