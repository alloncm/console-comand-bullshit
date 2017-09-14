
#include"Database.h"

using namespace alloncm;
int main()
{
	char c = 0;
	Database data;
	while (c!='e')
	{
		print("(l)oad (s)ave (a)dd (p)rint or (e)xit?\n");
		char a = getchar();
		getchar();
		int b;
		switch (a)
		{
		case 'l':
			data.Load("derp.txt");
			print("load complete\n");
			break;
		case 's':
			data.Save("derp.txt");
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
			data.Add(buf, b);
			break;
		case 'p':
			data.Print();
			break;
		case 'e':
			c = a;
			break;
		}	
	}
	//char buf[10];
	//int2str(2, buf);
	char str[] = "tree";
	ReverseStr(str);
	return 0;
}