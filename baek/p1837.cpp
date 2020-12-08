#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

const int MAX = 1000003;

int K, num;
char P[110];
int arr[MAX - 1];

void primeNum() {
    int sqrt_N = sqrt(MAX) - 1;
    for (int i = 2; i < sqrt_N; i++) {
        if (arr[i] == 0) continue;
        for (int j = i + i; j < MAX; j += i) {
            arr[j] = 0;
        }
    }
}

bool solve(int k) {
    int temp = 0;
    for (int i = 0; P[i]; i++) {
        temp = (temp * 10 + (P[i] - '0')) % k;
    }
    return temp == 0;
}

int main() {

    cin >> P >> K;

    for (int i = 2; i < MAX; i++) arr[i] = i;

    primeNum();

    bool flag = false;

    for (int i = 2; i < K; i++) {
        if (arr[i] == 0) continue;
        if (solve(i)) {
            flag = true;
            num = i;
            break;
        }
    }

    if (!flag) cout << "GOOD";
    else cout << "BAD " << num;

    return 0;
}