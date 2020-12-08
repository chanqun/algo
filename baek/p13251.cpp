#include<iostream>
using namespace std;

double sol=0;
int num[51];
int M, K;
int total = 0;
int main() {
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin>>num[i];
		total += num[i];
	}
	cin >> K;
	for (int i = 0; i < M; i++)
	{
		double temp = 1.0;
		if (K > num[i])	continue;
		for (int j = 0; j < K ; j++)
		{
			temp *= (double)(num[i] - j)/ (total - j);
		}
		sol += temp;
	}
	cout << fixed;
	cout.precision(15);
	cout << sol;

	return 0;
}