#include<iostream>
#include<vector>

using namespace std;


//n+1, n
//n  , n-1 행렬 거듭제곱을 통한 분할 정복
long long arr[2][2] = { {1,1},{1,0} };
void fibo(long long n)
{
	arr[0][0] = arr[0][0] * arr[0][0] + arr[0][1] * arr[1][0];
	arr[1][0] = arr[1][0] * arr[0][0] + arr[1][1] * arr[1][0];
	arr[0][1] = arr[0][0] * arr[0][1] + arr[0][1] * arr[1][1];
	arr[1][1] = arr[1][0] * arr[0][1] + arr[1][1] * arr[1][1];
}
pair<int,int> getnum(int n)
{
	int num = 1;
	int cnt = 0;
	while (cnt <= n)
	{
		num = num << 1;
		cnt++;
	}


	return { num, n-cnt };

}
int main()
{
	//string s;
	//cin >> s;

	//bool carry= false;
	//for (int i = 0; i < s.size(); i++)
	//{
	//	string tmp;
	//	int t;

	//	if(carry)
	//		t = s[i] - '0' + 5;

	//	carry = false;

	//	if (t % 2 == 1)
	//		carry = true;

	//	t--;
	//	t /= 2;

	//	tmp.push_back()

	//}

	int sum = 0;
	pair<int, int> p;
	p = getnum(10);
	sum += p.first;
	while (1){
		if (p.second != 0)
		{
			p = getnum(p.second);
			sum += p.first;
		}
		else
			break;
	}
	cout << sum;

	return 0;
}