//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
////n+1, n
////n  , n-1 행렬 거듭제곱을 통한 분할 정복
//
//long long arr[2][2] = { {1,1},{1,0} };
//void fibo(long long n)
//{
//	arr[0][0] = arr[0][0] * arr[0][0] + arr[0][1] * arr[1][0];
//	arr[1][0] = arr[1][0] * arr[0][0] + arr[1][1] * arr[1][0];
//	arr[0][1] = arr[0][0] * arr[0][1] + arr[0][1] * arr[1][1];
//	arr[1][1] = arr[1][0] * arr[0][1] + arr[1][1] * arr[1][1];
//}
//pair<vector<vector<long long>>, long long> getn(vector<vector<long long>>& adj,int size, int n)
//{
//	int sum = 0;
//	int cnt = 0;
//	vector<long long> init(size,0);
//	vector < vector<long long>> tmp = adj;
//	vector < vector<long long>> tmp2(size,init);
//	while (sum < n)
//	{
//		cnt++;
//		sum += cnt;
//		for(int k=0;k<size;k++)
//			for(int i=0;i<size;i++)
//				for (int j = 0; j < size; j++)
//				{
//					tmp2[i][k] += tmp[i][j] * tmp[j][i];
//				}
//
//		tmp = tmp2;
//	}
//
//	return { tmp2, n - sum };
//}
//int main()
//{
//	int n, b;
//	cin >> n >> b;
//
//	vector<vector<long long>> v(n);
//	vector<vector<long long>> ans(n);
//	for(int i=0;i<n;i++)
//		for (int j = 0; j < n; j++)
//		{
//			long long tmp;
//			cin >> tmp;
//			v[i].push_back(tmp);
//			ans[i].push_back(0);
//		}
//
//
//	vector<vector<long long>> tmp;
//
//
//
//	return 0;
//}