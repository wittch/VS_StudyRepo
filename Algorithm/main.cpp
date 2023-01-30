#include<iostream>

using namespace std;


int main()
{
	int A[10000];
	int n;
	cin >> n;
	int x;
	cin >> x;
	int i = 0;
	

	while (i < n)
	{
		cin >> A[i];
			i++;
	}
	i = 0;
	while (i < n)
	{
		if (A[i] < x)
		{
			cout << A[i] << endl;
		}
	
		i++;
	}




	return 0;
}










	//int N;
	//cin >> N;
	//int x;
	//x = 0;
	//int y;
	//y = 0;
	//int a;
	//a = 0;
	//int b;
	//b = 0;
	//int c;
	//c = 0;
	//int d;
	//d = 0;
	//int e;
	//e = 0;


	//for(int i=0; i<N; i++)
	//{
	//	cin >> x >> y;


	//     if (x == 0 || y == 0)
	//	{
	//	e++;

	//	}
	//	else if (x>0 && y>0)
	//	{
	//		a++;
	//		
	//	}
	//	else if (x<0 && y>0)
	//	{
	//		b++;
	//		
	//	}
	//	else if (x<0 && y<0)
	//	{
	//		c++;
	//		
	//	}
	//	else if (x>0 && y<0)
	//	{
	//		d++;
	//		
	//	}
	//
	//}
	//cout << "Q1:" << ' ' << a << endl;
	//cout << "Q2:" << ' ' << b << endl;
	//cout << "Q3:" << ' ' << c << endl;
	//cout << "Q4:" << ' ' << d << endl;
	//cout << "AXIS:" << ' ' << e << endl;

