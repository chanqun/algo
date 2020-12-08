#include <iostream>
#include <vector>
using namespace std;
//ДЉРћЧе gcdLtoR, gcdRtoL
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int gcdLtoR[1000001];
int gcdRtoL[1000001];
int N, a;
vector <int> num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		num.push_back(a);
	}
	gcdLtoR[0] = num[0];
	gcdRtoL[N - 1] = num[N - 1];
	for (int i = 1; i < N; i++)
	{
		gcdLtoR[i] = gcd(gcdLtoR[i - 1], num[i]);
		gcdRtoL[num.size()-i-1] = gcd(gcdRtoL[num.size() - i], num[num.size() - i-1]);
	}
	int maxGcd = 0,number=-1; 
	if (maxGcd < gcdRtoL[1]) {
		maxGcd = gcdRtoL[1];
		number = num[0];
	}
	for (int i = 1; i < N-1; i++) {
		int temp = gcd(gcdLtoR[i - 1], gcdRtoL[i + 1]);
		if (maxGcd < temp) {
			maxGcd = temp, number = num[i];
		}
	}
	if (maxGcd < gcdLtoR[N-1]) {
		maxGcd = gcdLtoR[N-2];
		number = num[N-1];
	}

	/*for (int i = 0; i < N; i++)
	{
		cout << gcdLtoR[i] << " " << gcdRtoL[i]<<"\n";
	}*/
	if (number%maxGcd==0) {
		cout << -1;
		return 0;
	}
	cout << maxGcd << " " << number;
	return 0;
}