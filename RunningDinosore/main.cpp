#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	char player[10][10] =
	{
		{},
		{},
		{},
		{},
		{},
		{},
		{' ','@','@','@','@'},
		{' ','@','@','@','@'},
		{'@','@','@','@','@','@'},
		{' ', 'O', ' ', ' ', 'O'}
	};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			cout << player[i][j];
		}
		cout << '\n';
	}

	char c;
	
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();
				char* buf;
				buf = &c;
					
			}
		}
	}
	


	return 0;
}