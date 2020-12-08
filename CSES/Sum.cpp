#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin>>N;

    ll ans = 1ll*(N*(N+1))/2;
    cout<<ans;
	return 0;
}