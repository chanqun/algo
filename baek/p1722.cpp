#include <iostream>

using namespace std;

int N;
int fact[21];
bool chk[21];

int main() {

	cin >> N;
	fact[1] = 1;
	for (int i = 2; i < 21; i++)
	{
		fact[i] = fact[i - 1] * i;
	}
	int a;
	int cnt = 0;
	cin >> a;
	if (a == 1) {
        cin >> a;
        for(int i=1;i<=N;i++){
            if(a>=fact[N-i]){
                cnt+=fact[N-i];
            }
        }
	}
	else {
		for (int i = N - 1; i > 0; i--)
		{
			cin >> a;
			chk[a] = true;
			for (int j = 1; j < a; j++) {
				if (!chk[j]) {
					cnt += fact[i];
				}
			}
		}
		cnt++;
		cout << cnt;
	}

	return 0;
}